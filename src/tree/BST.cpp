#include <iostream>
#include <vector>
#include "stack.h"
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

class BinaryTree
{
protected:
    BTreeNode* root;

protected:
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

    int numOfNodes(BTreeNode* node)
    {
        if (node)
            return 1 + numOfNodes(node->left) + numOfNodes(node->right);
        return 0;
    }

    int getHeight_1(BTreeNode* node, int h)
    {
        static int height = 0;
        if (node)
        {
            if (h > height)
                height = h;
            getHeight_1(node->left, h + 1);
            getHeight_1(node->right, h + 1);

        }
        return height;
    }

    int getHeight_2(BTreeNode* node)
    {
        if (node)
        {
            int leftHeight = getHeight_2(node->left);
            int rightHeight = getHeight_2(node->right);
            if (leftHeight > rightHeight)
                return leftHeight + 1;
            else
                return rightHeight + 1;
        }
        return -1;
    }

    int getNumOfLeaves(BTreeNode* node)
    {
        if (node == nullptr)
            return 0;

        if (node && node->left == nullptr && node->right == nullptr)
            return 1;

        return getNumOfLeaves(node->left) + getNumOfLeaves(node->right);
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void createTree()
    {
        BTreeNodeQueue queue;
        cout << "root : ";
        int data;
        cin >> data;
        root = new BTreeNode(data);
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
    }

    void PreorderDisplay()
    {
        PreorderDisplay(root);
    }

    void PreorderDisplayIterative()
    {
        LinkedListStack<BTreeNode*> stack;
        BTreeNode* current = root;
        while (current || stack.isEmpty() == false)
        {
            if (current)
            {
                cout << current->data << " ";
                stack.push(current);
                current = current->left;
            }
            else
            {
                current = stack.pop();
                current = current->right;
            }
        }
    }

    void InorderDisplay()
    {
        InorderDisplay(root);
    }

    void InorderDisplayIterative()
    {
        LinkedListStack<BTreeNode*> stack;
        BTreeNode* current = root;
        while (current || stack.isEmpty() == false)
        {
            if (current)
            {

                stack.push(current);
                current = current->left;
            }
            else
            {
                current = stack.pop();
                cout << current->data << " ";
                current = current->right;
            }
        }
    }

    void PostorderDisplay()
    {
        PostorderDisplay(root);
    }

    void LevelOrderDisplay()
    {
        if (root == nullptr)
            return;

        BTreeNodeQueue queue;
        queue.enQueue(root);
        while (queue.isEmpty() == false)
        {
            BTreeNode* current = queue.deQueue();
            cout << current->data << " ";

            if (current->left)
                queue.enQueue(current->left);
            if (current->right)
                queue.enQueue(current->right);
        }
        cout << endl;
    }

    int numOfNodes()
    {
        return numOfNodes(root);
    }

    int getHeight_1()
    {
        return getHeight_1(root, 0);
    }

    int getHeight_2()
    {
        return getHeight_2(root);
    }

    int getNumOfLeaves()
    {
        return getNumOfLeaves(root);
    }
};

class BinarySearchTree : public BinaryTree
{
private:
    BTreeNode* InsertRecursive(BTreeNode* current, int data)
    {
        if (current == nullptr)
            return new BTreeNode(data);

        if (current->data < data)
            current->right = InsertRecursive(current->right, data);
        else
            current->left = InsertRecursive(current->left, data);

        return current;
    }

    BTreeNode* DeleteRecursive(BTreeNode* current, int data)
    {
        if (current == nullptr)
            return nullptr;

        if (current->left == nullptr && current->right == nullptr)
        {
            if (current == root)
                root = nullptr;
            delete current;
            return nullptr;
        }

        if (current->data < data)
            current->right = DeleteRecursive(current->right, data);
        else if (current->data > data)
            current->left = DeleteRecursive(current->left, data);
        else //(current->data == data)
        {
            if (getHeight_2(current->left) < getHeight_2(current->right))
            {
                BTreeNode* InorderSucc = current->right;
                while (InorderSucc && InorderSucc->left)
                    InorderSucc = InorderSucc->left;

                current->data = InorderSucc->data;
                current->right = DeleteRecursive(current->right, InorderSucc->data);
            }
            else
            {
                BTreeNode* InorderPre = current->left;
                while (InorderPre && InorderPre->right)
                    InorderPre = InorderPre->right;

                current->data = InorderPre->data;
                current->left = DeleteRecursive(current->left, InorderPre->data);
            }
        }
        return current;
    }

public:
    BinarySearchTree() : BinaryTree()
    {

    }

    void createBSTFromPreorders(vector<int> v)
    {
        if (v.size() == 0)
            return;

        LinkedListStack<BTreeNode*> st;

        int i = 0;
        root = new BTreeNode(v[i++]);
        BTreeNode* current = root;

        while (i < v.size())
        {
            int data = v[i];
            if (data < current->data)
            {
                BTreeNode* newNode = new BTreeNode(v[i++]);
                current->left = newNode;
                st.push(current);
                current = newNode;
            }
            else if (current->data < data && (st.isEmpty() || (data <= st.peek()->data)))
            {
                BTreeNode* newNode = new BTreeNode(v[i++]);
                current->right = newNode;
                current = newNode;
            }
            else
            {
                current = st.pop();
            }
        }
    }



    bool HasNodeUnOptimized(int data)
    {
        if (root == nullptr)
            return false;

        BTreeNodeQueue queue;
        queue.enQueue(root);
        while (queue.isEmpty() == false)
        {
            BTreeNode* current = queue.deQueue();
            if (current->data == data)
                return true;

            if (current->left)
                queue.enQueue(current->left);
            if (current->right)
                queue.enQueue(current->right);
        }
        return false;
    }

    bool HasNode(int data)
    {
        BTreeNode* current = root;
        while (current)
        {
            if (current->data == data)
                return true;

            if (current->data < data)
                current = current->right;
            else
                current = current->left;
        }
        return false;
    }

    void Insert(int data)
    {
        BTreeNode* newNode = new BTreeNode(data);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        BTreeNode* prev = nullptr;
        BTreeNode* current = root;
        while (current)
        {
            prev = current;
            if (current->data < data)
                current = current->right;
            else
                current = current->left;
        }

        if (prev->data < data)
            prev->right = newNode;
        else
            prev->left = newNode;
    }

    void InsertRecursive(int data)
    {
        root = InsertRecursive(root, data);
    }

    void DeleteRecursive(int data)
    {
        root = DeleteRecursive(root, data);
    }
};


/*
int main()
{

    BinaryTree bTree;
    bTree.createTree();

    bTree.PreorderDisplay(); cout << endl;
    bTree.PreorderDisplayIterative(); cout << endl; cout << endl;

    bTree.InorderDisplay(); cout << endl;
    bTree.InorderDisplayIterative(); cout << endl; cout << endl;

    bTree.PostorderDisplay(); cout << endl; cout << endl;
    //Postorder 의 Iterative 버전은 많이 복잡함, 보통 다루지 않음.

    bTree.LevelOrderDisplay(); cout << endl; cout << endl;

    cout << "num of nodes : " << bTree.numOfNodes() << endl;
    cout << "num of leaves : " << bTree.getNumOfLeaves() << endl;
    cout << "height of nodes : " << bTree.getHeight_1() << endl;
    cout << "height of nodes : " << bTree.getHeight_2() << endl;


BinarySearchTree BSTree;
//BSTree.Insert(9);
//BSTree.Insert(15);
//BSTree.Insert(5);
//BSTree.Insert(20);
//BSTree.Insert(16);
//BSTree.Insert(8);
//BSTree.Insert(12);
//BSTree.Insert(3);
//BSTree.Insert(6);
BSTree.InsertRecursive(9);
BSTree.InsertRecursive(15);
BSTree.InsertRecursive(5);
BSTree.InsertRecursive(20);
BSTree.InsertRecursive(16);
BSTree.InsertRecursive(8);
BSTree.InsertRecursive(12);
BSTree.InsertRecursive(3);
BSTree.InsertRecursive(6);
//             9
//         5       15
//       3   8   12  20
//          6       16
BSTree.LevelOrderDisplay();

//O(logN)
cout << endl;
cout << BSTree.HasNode(5) << endl;
cout << BSTree.HasNode(16) << endl;
cout << BSTree.HasNode(9) << endl;
cout << BSTree.HasNode(13) << endl;//false
cout << BSTree.HasNode(12) << endl;

//O(n)
cout << endl;
cout << BSTree.HasNodeUnOptimized(5) << endl;
cout << BSTree.HasNodeUnOptimized(16) << endl;
cout << BSTree.HasNodeUnOptimized(9) << endl;
cout << BSTree.HasNodeUnOptimized(13) << endl;//false
cout << BSTree.HasNodeUnOptimized(12) << endl;

//             9
//         5       15
//       3   8   12  20
//                  16   
BSTree.DeleteRecursive(6);
BSTree.LevelOrderDisplay();


//             9
//         5       15
//       3   8   12  16
//                 
BSTree.DeleteRecursive(20);
BSTree.LevelOrderDisplay();

//             9
//         5       12
//       3   8       16
//                 
BSTree.DeleteRecursive(15);
BSTree.LevelOrderDisplay();
BSTree.DeleteRecursive(10);
BSTree.LevelOrderDisplay();

//             8
//         5       12
//       3           16
//                 
BSTree.DeleteRecursive(9);
BSTree.LevelOrderDisplay();


//             30
//      20             40
//  10      25              50
//    15                   45
cout << endl << endl;
BinarySearchTree BSTree_2;
vector<int> preOrders = { 30,20,10,15,25,40,50,45 };
BSTree_2.createBSTFromPreorders(preOrders);
BSTree_2.LevelOrderDisplay();

system("pause");

return 0;
}
*/