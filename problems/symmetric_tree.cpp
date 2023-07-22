#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

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
            delete left;
        if (right)
            delete right;
    }
};

bool solve(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (!root1 || !root2)
        return true;

    if (root1->data != root2->data)
        return false;

    return solve(root1->left, root2->right) && solve(root1->right, root2->left);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return true;
    return solve(root->left, root->right);
}