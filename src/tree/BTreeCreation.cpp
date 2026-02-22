#include <iostream>
#include <vector>

using namespace std;

struct BTreeNode
{
    int data;
    BTreeNode* left;
    BTreeNode* right;
    BTreeNode(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class BTreeNodeQueue
{
    struct Node
    {
        BTreeNode* bTreeNode;
        Node* next;
        Node(BTreeNode* bTreeNode)
        {
            this->bTreeNode = bTreeNode;
            next = nullptr;
        }
    };

private:
    Node* first;
    Node* last;

public:
    BTreeNodeQueue()
    {
        first = nullptr;
        last = nullptr;
    }

    void enQueue(BTreeNode* bTreeNode)
    {
        Node* newNode = new Node(bTreeNode);

        if (isEmpty())
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    BTreeNode* deQueue()
    {
        if (isEmpty())
            throw runtime_error("Queue is empty");

        BTreeNode* data = first->bTreeNode;
        Node* node = first;
        first = first->next;
        delete node;
        return data;
    }

    bool isEmpty()
    {
        return first == nullptr;
    }
};



BTreeNode* createTree()
{
    BTreeNodeQueue queue;
    cout << "root : ";
    int data;
    cin >> data;
    BTreeNode* root = new BTreeNode(data);
    queue.enQueue(root);

    while (queue.isEmpty() == false)
    {
        BTreeNode* currentroot = queue.deQueue();

        int leftdata;
        cout << "left of " << currentroot->data << ":";
        cin >> leftdata;
        if (leftdata != -1)
        {
            BTreeNode* left = new BTreeNode(leftdata);
            currentroot->left = left;
            queue.enQueue(left);
        }

        int rightdata;
        cout << "right of " << currentroot->data << ":";
        cin >> rightdata;
        if (rightdata != -1)
        {
            BTreeNode* right = new BTreeNode(rightdata);
            currentroot->right = right;
            queue.enQueue(right);
        }
    }

    return root;

}

void PreorderDisplay(BTreeNode* current)
{
    if (current == nullptr)
        return;

    cout << current->data << " ";
    PreorderDisplay(current->left);
    PreorderDisplay(current->right);
}

void InorderDisplay(BTreeNode* current)
{
    if (current == nullptr)
        return;

    InorderDisplay(current->left);
    cout << current->data << " ";
    InorderDisplay(current->right);
}

void PostorderDisplay(BTreeNode* current)
{
    if (current == nullptr)
        return;

    PostorderDisplay(current->left);
    PostorderDisplay(current->right);
    cout << current->data << " ";
}

/*
int main()
{
    BTreeNode* root = createTree();
    PreorderDisplay(root); cout << endl;
    InorderDisplay(root); cout << endl;
    PostorderDisplay(root); cout << endl;

    system("pause");

    return 0;
}
*/