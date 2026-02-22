#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;

struct AVLTreeNode
{
    int data;
    int height;
    AVLTreeNode* left;
    AVLTreeNode* right;
    AVLTreeNode(int data, int height)
    {
        this->data = data;
        this->height = height;
        left = right = nullptr;
    }
};


class AVLTree
{
private:
    AVLTreeNode* root;

private:
    int getHeight(AVLTreeNode* current)
    {
        //if (current == nullptr)
        //    return -1;

        //int x = getHeight(current->left) + 1;
        //int y = getHeight(current->right) + 1;
        //return (x > y) ? x : y;

        int x = (current && current->left) ? (current->left->height + 1) : 0;
        int y = (current && current->right) ? (current->right->height + 1) : 0;
        return (x > y) ? x : y;
    }

    int getBalanceFactor(AVLTreeNode* current)
    {
        int x = (current && current->left) ? (current->left->height) : -1;
        int y = (current && current->right) ? (current->right->height) : -1;
        return x - y;
    }

    AVLTreeNode* Rotate_LL(AVLTreeNode* current)
    {
        AVLTreeNode* left = current->left;
        AVLTreeNode* leftRight = left->right;

        left->right = current;
        current->left = leftRight;

        current->height = getHeight(current);
        left->height = getHeight(left);

        if (root == current)
            root = left;

        return left;
    }

    AVLTreeNode* Rotate_LR(AVLTreeNode* current)
    {
        AVLTreeNode* L = current->left;
        AVLTreeNode* LR = L->right;
        AVLTreeNode* LRL = LR->left;
        AVLTreeNode* LRR = LR->right;

        L->right = LRL;
        current->left = LRR;
        LR->left = L;
        LR->right = current;

        current->height = getHeight(current);
        L->height = getHeight(L);
        LR->height = getHeight(LR);

        if (current == root)
            root = LR;

        return LR;
    }

    AVLTreeNode* Rotate_RR(AVLTreeNode* current)
    {
        AVLTreeNode* R = current->right;
        AVLTreeNode* RL = R->left;

        current->right = RL;
        R->left = current;

        current->height = getHeight(current);
        R->height = getHeight(R);

        if (current == root)
            root = R;

        return R;
    }

    AVLTreeNode* Rotate_RL(AVLTreeNode* current)
    {
        AVLTreeNode* R = current->right;
        AVLTreeNode* RL = R->left;
        AVLTreeNode* RLL = RL->left;
        AVLTreeNode* RLR = RL->right;

        RL->right = R;
        RL->left = current;
        current->right = RLL;
        R->left = RLR;

        current->height = getHeight(current);
        R->height = getHeight(R);
        RL->height = getHeight(RL);

        if (root == current)
            root = RL;

        return RL;
    }

    AVLTreeNode* InsertRecursive(AVLTreeNode* current, int data)
    {
        if (current == nullptr)
            return new AVLTreeNode(data, 0);

        if (current->data < data)
            current->right = InsertRecursive(current->right, data);
        else
            current->left = InsertRecursive(current->left, data);

        current->height = getHeight(current);

        //LL Rotation (AVL Tree Recunstruction)
        if (getBalanceFactor(current) == 2 && getBalanceFactor(current->left) == 1)
            return Rotate_LL(current);
        if (getBalanceFactor(current) == 2 && getBalanceFactor(current->left) == -1)
            return Rotate_LR(current);
        if (getBalanceFactor(current) == -2 && getBalanceFactor(current->right) == -1)
            return Rotate_RR(current);
        if (getBalanceFactor(current) == -2 && getBalanceFactor(current->right) == 1)
            return Rotate_RL(current);

        return current;
    }

    void PreorderDisplay(AVLTreeNode* current)
    {
        if (current == nullptr)
            return;

        cout << current->data << "(height : " << current->height << ")" << endl;
        PreorderDisplay(current->left);
        PreorderDisplay(current->right);
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void InsertRecursive(int data)
    {
        root = InsertRecursive(root, data);
    }

    void PreorderDisplay()
    {
        PreorderDisplay(root);
    }

    int getMaxHeight()
    {
        return getHeight(root);
    }

};

/*
int main()
{
    AVLTree avl_tree;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 100; i++)
    {
        int randomNum = rand() % 1000 + 1;
        avl_tree.InsertRecursive(randomNum);
    }
    cout << "max height : " << avl_tree.getMaxHeight() << endl;
    system("pause");

    return 0;
}
*/