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

class SortedLinkedList
{
private:
    Node* head;

public:
    SortedLinkedList()
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
            Node* current = head;
            if (node->data < head->data)
            {
                node->next = head;
                head = node;
                return;
            }
            if (head->next == nullptr)
            {
                head->next = node;
                return;
            }

            Node* prev = head;
            current = head->next;
            while (current)
            {
                if (prev->data <= node->data && node->data <= current->data)
                {
                    node->next = current;
                    prev->next = node;
                    return;
                }
                prev = current;
                current = current->next;
            }
            prev->next = node;
        }
    }

    void merge(SortedLinkedList* second)
    {
        Node* last = nullptr;
        Node* first_current = this->head;
        Node* second_current = second->head;

        if (first_current == nullptr)
        {
            this->head = second->head;
            return;
        }
        if (second_current == nullptr)
            return;

        while (first_current && second_current)
        {
            if (first_current->data < second_current->data)
            {
                if (last == nullptr)
                    last = first_current;
                else
                {
                    last->next = first_current;
                    last = first_current;
                }
                first_current = first_current->next;
            }
            else
            {
                if (last == nullptr)
                    last = second_current;
                else
                {
                    last->next = second_current;
                    last = second_current;
                }
                second_current = second_current->next;
            }
        }

        if (first_current)
            last->next = first_current;
        if (second_current)
            last->next = second_current;
    }

    void removeDuplicate()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* prev = head;
        Node* current = head->next;

        while (current)
        {
            if (prev->data == current->data)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }

    void displayAll()
    {
        Node* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

/*
int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(6);

    SortedLinkedList l1;

    l1.Add(2);
    l1.Add(4);
    l1.Add(1);
    l1.Add(6);
    l1.Add(5);
    l1.Add(5);
    l1.Add(1);
    l1.Add(11);
    l1.Add(7);
    l1.Add(11);
    l1.Add(5);
    l1.Add(1);
    l1.displayAll();

    l1.removeDuplicate();
    l1.displayAll();

    SortedLinkedList l2;
    l2.Add(3);
    l2.Add(9);
    l2.Add(8);
    l2.Add(10);
    l2.displayAll();

    l1.merge(&l2);
    l1.displayAll();
    return 0;
}
*/