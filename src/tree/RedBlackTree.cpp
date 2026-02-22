#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "stack.h"
using namespace std;

struct RedBlackTreeNode
{
    int data;
    bool isBlack;
    RedBlackTreeNode* left;
    RedBlackTreeNode* right;
    RedBlackTreeNode(int data, bool isBlack)
    {
        this->data = data;
        this->isBlack = isBlack;
        left = right = nullptr;
    }
};

// 1. Root of tree is always black
// 2. Null node is also black
// 3. Num of blacks on paths from root to leaf are same
// 4. No consecutive Reds (Parent and children of Red are Black)
// 5. New inserted node is Red
// 6. height : logN <= h <= 2*logN
class RedBlackTree
{
private:
    RedBlackTreeNode* root;

private:
    int getHeight(RedBlackTreeNode* current)
    {
        if (current == nullptr)
            return -1;

        int x = getHeight(current->left) + 1;
        int y = getHeight(current->right) + 1;
        return (x > y) ? x : y;
    }

    bool isRed(RedBlackTreeNode* node)
    {
        if (node == nullptr)
            return false;
        return !node->isBlack;
    }

    void flipColors(RedBlackTreeNode* node)
    {
        node->isBlack = !node->isBlack;
        if (node->left)
            node->left->isBlack = !node->left->isBlack;
        if (node->right)
            node->right->isBlack = !node->right->isBlack;
    }

    RedBlackTreeNode* rotateLeft(RedBlackTreeNode* current)
    {
        RedBlackTreeNode* R = current->right;
        RedBlackTreeNode* RL = R->left;

        R->left = current;
        current->right = RL;

        R->isBlack = current->isBlack;
        current->isBlack = false;

        if (root == current)
            root = R;

        return R;
    }

    RedBlackTreeNode* rotateRight(RedBlackTreeNode* current)
    {
        RedBlackTreeNode* L = current->left;
        RedBlackTreeNode* LR = L->right;

        L->right = current;
        current->left = LR;

        L->isBlack = current->isBlack;
        current->isBlack = false;

        if (root == current)
            root = L;

        return L;
    }

    //Red-Black Tree 구현 방식은 다양함
    //여기 적용된 Left-Leaning Red-Black Tree (LLRB)는 Red-Black Tree의 한 변형으로
    //Red 노드가 왼쪽 자식으로만 연결되도록 강제하는 방식임
    //3가지 간단한 케이스로 균형 유지, 코드가 매우 간결(현재 구현 방식)
    RedBlackTreeNode* balance(RedBlackTreeNode* current)
    {
        if (isRed(current->right) && !isRed(current->left))
            current = rotateLeft(current);

        if (isRed(current->left) && current->left && isRed(current->left->left))
            current = rotateRight(current);

        if (isRed(current->left) && isRed(current->right))
            flipColors(current);

        return current;
    }

    // Move red link to left
    RedBlackTreeNode* moveRedLeft(RedBlackTreeNode* current)
    {
        flipColors(current);

        if (current->right && isRed(current->right->left))
        {
            current->right = rotateRight(current->right);
            current = rotateLeft(current);
            flipColors(current);
        }

        return current;
    }

    // Move red link to right
    RedBlackTreeNode* moveRedRight(RedBlackTreeNode* current)
    {
        flipColors(current);

        if (current->left && isRed(current->left->left))
        {
            current = rotateRight(current);
            flipColors(current);
        }

        return current;
    }

    // Find minimum node
    RedBlackTreeNode* findMin(RedBlackTreeNode* current)
    {
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Delete minimum node
    RedBlackTreeNode* deleteMin(RedBlackTreeNode* current)
    {
        if (current->left == nullptr)
        {
            delete current;
            return nullptr;
        }

        if (!isRed(current->left) && !isRed(current->left->left))
            current = moveRedLeft(current);

        current->left = deleteMin(current->left);

        return balance(current);
    }

    RedBlackTreeNode* InsertRecursive(RedBlackTreeNode* current, int data)
    {
        // Base case: create new red node
        if (current == nullptr)
            return new RedBlackTreeNode(data, false);

        // Standard BST insertion
        if (data < current->data)
            current->left = InsertRecursive(current->left, data);
        else if (data > current->data)
            current->right = InsertRecursive(current->right, data);
        else
            return current; // Duplicate values not allowed in Red-Black Tree

        return balance(current);
    }

    RedBlackTreeNode* DeleteRecursive(RedBlackTreeNode* current, int data)
    {
        if (current == nullptr)
            return nullptr;

        // Search for node to delete
        if (data < current->data)
        {
            // Going left
            if (current->left && !isRed(current->left) && !isRed(current->left->left))
                current = moveRedLeft(current);

            current->left = DeleteRecursive(current->left, data);
        }
        else
        {
            // Lean left red links to right
            if (isRed(current->left))
                current = rotateRight(current);

            // Found node at bottom (leaf)
            if (data == current->data && current->right == nullptr)
            {
                delete current;
                return nullptr;
            }

            // Going right
            if (current->right && !isRed(current->right) && !isRed(current->right->left))
                current = moveRedRight(current);

            // Found node in middle
            if (data == current->data)
            {
                // Replace with successor
                RedBlackTreeNode* successor = findMin(current->right);
                current->data = successor->data;
                current->right = deleteMin(current->right);
            }
            else
            {
                current->right = DeleteRecursive(current->right, data);
            }
        }

        // Fix right-leaning red links and eliminate 4-nodes on the way up
        return balance(current);
    }

    void preorderDisplay(RedBlackTreeNode* current)
    {
        if (current == nullptr)
            return;

        cout << current->data << (current->isBlack ? "(B) " : "(R) ");
        preorderDisplay(current->left);
        preorderDisplay(current->right);
    }

public:
    RedBlackTree()
    {
        root = nullptr;
    }

    void InsertRecursive(int data)
    {
        root = InsertRecursive(root, data);
        root->isBlack = true; // Rule 1: Root is always black (Root 강제 Black)
    }

    void DeleteRecursive(int data)
    {
        if (root == nullptr)
            return;

        // Make root red temporarily to simplify delete
        if (!isRed(root->left) && !isRed(root->right))
            root->isBlack = false;

        root = DeleteRecursive(root, data);

        // Restore root to black
        if (root != nullptr)
            root->isBlack = true;
    }

    int getMaxHeight()
    {
        return getHeight(root);
    }

    void preorderDisplay()
    {
        preorderDisplay(root);
        cout << endl;
    }
};

/*
int main()
{
    RedBlackTree rbt;
    srand(static_cast<unsigned int>(time(0)));

    cout << "=== Inserting 10 random numbers ===" << endl;

    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        int randomNum = rand() % 100 + 1;
        v.push_back(randomNum);
        cout << "Inserting: " << randomNum << endl;
        rbt.InsertRecursive(randomNum);
    }

    cout << "\n=== Tree after insertion ===" << endl;
    rbt.preorderDisplay();
    cout << "max height : " << rbt.getMaxHeight() << endl;

    rbt.DeleteRecursive(v[0]);
    rbt.DeleteRecursive(v[1]);
    rbt.DeleteRecursive(v[2]);
    rbt.DeleteRecursive(v[3]);
    rbt.DeleteRecursive(v[4]);
    rbt.DeleteRecursive(10000);
    rbt.preorderDisplay();
    cout << "max height : " << rbt.getMaxHeight() << endl;

    system("pause");

    return 0;
}
*/