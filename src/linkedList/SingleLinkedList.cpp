#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using namespace std::chrono;

struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
protected:
    Node* head;

private:
    Node* getLastNode()
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node* current = head;
        while (current->next)
            current = current->next;
        return current;
    }

public:
    LinkedList()
    {
        head = nullptr;
    }

    void Add(int value)
    {
        Node* node = new Node(value);
        if (head == nullptr)
        {
            head = node;
        }
        else
        {
            Node* last = getLastNode();
            last->next = node;
            last = node;
        }
    }

    void ConcatLinkedList(LinkedList* second)
    {
        Node* firstLast = getLastNode();
        firstLast->next = second->head;
    }

    virtual void displayAll() = 0;
    virtual void displaySum() = 0;
    virtual void displayMaximum() = 0;
    virtual bool contains(int value) = 0;
    virtual bool improved_contains(int value) = 0;//move_to_head
    virtual void insert(int value, int index) = 0;
    virtual void Delete(int index) = 0;
    virtual void reverse() = 0;
};

class LinkedListInterative : public LinkedList
{
public:

    virtual void displayAll() override
    {
        Node* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    virtual void displaySum() override
    {
        Node* current = head;
        int sum = 0;
        while (current)
        {
            sum += current->data;
            current = current->next;
        }
        cout << "sum : " << sum << endl;
    }

    virtual void displayMaximum() override
    {
        Node* current = head;
        int maximum = INT64_MIN;
        while (current)
        {
            if (current->data > maximum)
                maximum = current->data;
            current = current->next;
        }
        cout << "maximum : " << maximum << endl;
    }

    virtual bool contains(int value) override
    {
        Node* current = head;
        while (current)
        {
            if (value == current->data)
                return true;
            current = current->next;
        }
        return false;
    }

    virtual bool improved_contains(int value) override
    {
        Node* prev = nullptr;
        Node* current = head;
        while (current)
        {
            if (value == current->data)
            {
                //[pointer 변경 방식]
                if (prev)
                {
                    prev->next = current->next;
                    current->next = head;
                    head = current;
                }

                //[값 복사 방식]
                //int tmp = current->data;
                //current->data = head->data;
                //head->data = tmp;

                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }


    virtual void insert(int value, int index) override
    {
        try
        {
            if (index < 0)
                throw runtime_error("index out of range");

            Node* current = head;
            if (index == 0)
            {
                Node* newNode = new Node(value);
                newNode->next = head;
                head = newNode;
            }
            else
            {
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                    if (current == nullptr)
                        throw runtime_error("index out of range");
                }
                Node* newNode = new Node(value);
                newNode->next = current->next;
                current->next = newNode;
            }
        }
        catch (const runtime_error& ex)
        {
            cout << ex.what() << endl;
        }
    }

    virtual void Delete(int index) override
    {
        if (index == 0)
        {
            if (head != nullptr)
            {
                Node* nextNode = head->next;
                delete head;
                head = nextNode;
            }
        }
        else if (index > 0)
        {
            Node* prev = nullptr;
            Node* current = head;
            for (int i = 0; i < index && current; i++)
            {
                prev = current;
                current = current->next;
            }

            if (current)
            {
                prev->next = current->next;
                delete current;
            }
        }
    }

    virtual void reverse() override
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* prev = nullptr;
        Node* current = head;
        while (current)
        {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

};

class LinkedListRecursive : public LinkedList
{
private:
    void displayAllRecursive(Node* current)
    {
        if (current == nullptr)
            return;
        cout << current->data << " ";
        displayAllRecursive(current->next);
    }

    int getSumRecursive(Node* current)
    {
        if (current == nullptr)
            return 0;
        else
            return current->data + getSumRecursive(current->next);
    }

    int getMaximumRecursive(Node* current)
    {
        if (current == nullptr)
            return INT64_MIN;
        int currentMaximum = getMaximumRecursive(current->next);
        return (current->data > currentMaximum) ? current->data : currentMaximum;
    }

    bool contains(Node* current, int value)
    {
        if (current == nullptr)
            return false;
        return (current->data == value) ? true : contains(current->next, value);
    }

    bool improved_contains(Node* prev, Node* current, int value)
    {
        if (current == nullptr)
            return false;

        if (current->data == value)
        {
            //[pointer 변경 방식]
            if (prev)
            {
                prev->next = current->next;
                current->next = head;
                head = current;
            }

            //[값 복사 방식]
            //int tmp = current->data;
            //current->data = head->data;
            //head->data = tmp;

            return true;
        }

        return improved_contains(current, current->next, value);
    }

    //여기서 Node*& node 이거 꼭 참조로 전달 되어야 함 (즉, head가 참조로 전달 되어야함)
    //조금만 생각해보면 당연한것.
    void insert(Node*& node, Node* newNode, int currentIndex, int index)
    {
        if (index < 0 || node == nullptr)
            throw runtime_error("index out of range");

        if (index == 0)
        {
            newNode->next = node;
            node = newNode;
            return;
        }

        if (currentIndex == index - 1)
        {
            newNode->next = node->next;
            node->next = newNode;
            return;
        }

        insert(node->next, newNode, currentIndex + 1, index);
    }

    void Delete(Node* prev, Node* current, int currentIndex, int index)
    {
        if (index == 0)
        {
            if (head != nullptr)
            {
                Node* nextNode = head->next;
                delete head;
                head = nextNode;
                return;
            }
        }

        if (current == nullptr)
            return;

        if (currentIndex == index)
        {
            prev->next = current->next;
            delete current;
            return;

        }

        Delete(current, current->next, currentIndex + 1, index);
    }

public:
    virtual void displayAll() override
    {
        displayAllRecursive(head);
        cout << endl;
    }

    virtual void displaySum() override
    {
        cout << "sum : " << getSumRecursive(head) << endl;
    }

    virtual void displayMaximum() override
    {
        cout << "maximum : " << getMaximumRecursive(head) << endl;
    }

    virtual bool contains(int value) override
    {
        return contains(head, value);
    }

    virtual bool improved_contains(int value) override
    {
        return improved_contains(nullptr, head, value);
    }

    virtual void insert(int value, int index) override
    {
        try
        {
            Node* newNode = new Node(value);
            insert(head, newNode, 0, index);
        }
        catch (const runtime_error& ex)
        {
            cout << ex.what() << endl;
        }
    }

    virtual void Delete(int index) override
    {
        Delete(nullptr, head, 0, index);
    }

    void reverse(Node* prev, Node* current)
    {
        if (current == nullptr)
        {
            head = prev;
            return;
        }

        //Node* next = current->next;
        //current->next = prev;
        //reverse(current, next);

        //위에꺼랑 같은 효과임, 이러한 Stack 특성 활용하는 방향으로 가능하면 적용
        reverse(current, current->next);
        current->next = prev;
    }

    virtual void reverse() override
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* prev = nullptr;
        Node* current = head;
        reverse(prev, current);
    }
};

void Test(LinkedList* linkedList)
{
    linkedList->Add(1);
    linkedList->Add(4);
    linkedList->Add(10);
    linkedList->Add(6);
    linkedList->Add(8);
    linkedList->Add(9);

    cout << endl;
    linkedList->displayAll();
    linkedList->reverse();
    linkedList->displayAll();
    linkedList->reverse();
    linkedList->displayAll();
    linkedList->displaySum();
    linkedList->displayMaximum();
    cout << "contains 2 : " << linkedList->contains(2) << endl;//false
    cout << "contains 6 : " << linkedList->contains(6) << endl;//true
    cout << "contains 7 : " << linkedList->contains(7) << endl;//false

    cout << "[if found move to head] improved_contains 6 : " << linkedList->improved_contains(6) << endl;//true
    linkedList->displayAll();
    cout << "[if found move to head] improved_contains 2 : " << linkedList->improved_contains(2) << endl;//false
    linkedList->displayAll();
    cout << "[if found move to head] improved_contains 9 : " << linkedList->improved_contains(9) << endl;//false
    linkedList->displayAll();

    linkedList->insert(-100, -1);//index out of range
    linkedList->displayAll();

    linkedList->insert(100, 0);
    linkedList->displayAll();

    linkedList->insert(200, 2);
    linkedList->displayAll();

    linkedList->insert(800, 8);
    linkedList->displayAll();

    linkedList->insert(1000, 10);//index out of range
    linkedList->displayAll();

    linkedList->Delete(0);
    linkedList->displayAll();
    linkedList->Delete(0);
    linkedList->displayAll();
    linkedList->Delete(3);
    linkedList->displayAll();
    linkedList->Delete(3);
    linkedList->displayAll();
    linkedList->Delete(3);
    linkedList->displayAll();
    linkedList->Delete(3);
    linkedList->displayAll();
    linkedList->Delete(3);
    linkedList->displayAll();
}

/*
int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(6);

    LinkedList* l1 = new LinkedListInterative();
    LinkedList* l2 = new LinkedListRecursive();

    Test(l1);
    Test(l2);

    cout << endl;
    l1->ConcatLinkedList(l2);
    l1->displayAll();

    delete l1;
    delete l2;

    return 0;
}
*/