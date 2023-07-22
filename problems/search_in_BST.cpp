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
};

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    BinaryTreeNode<int> *curr = root;
    while (curr)
    {
        if (curr->data == x)
            return true;
        else if (curr->data < x)
            curr = curr->right;
        else
            curr = curr->left;
    }
    return false;
}