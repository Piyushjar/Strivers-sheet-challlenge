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

void traverse(BinaryTreeNode<int> *root, vector<int> &ino, vector<int> &pre, vector<int> &post)
{
    if (!root)
        return;

    pre.push_back(root->data);
    traverse(root->left, ino, pre, post);
    ino.push_back(root->data);
    traverse(root->right, ino, pre, post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<int> ino, pre, post;

    traverse(root, ino, pre, post);

    res.push_back(ino);
    res.push_back(pre);
    res.push_back(post);

    return res;
}