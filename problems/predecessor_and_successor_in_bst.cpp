#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.
    BinaryTreeNode<int> *curr = root;
    int succ = -1, prec = -1;
    while (curr)
    { // successor
        if (curr->data > key)
        {
            succ = curr->data;
            curr = curr->left;
        }
        else
            curr = curr->right;
    }
    curr = root;
    while (curr)
    { // predecessor
        if (curr->data < key)
        {
            prec = curr->data;
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
    return {prec, succ};
}
