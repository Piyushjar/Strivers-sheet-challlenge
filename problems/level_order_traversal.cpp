#include <bits/stdc++.h>
using namespace std;

// Following is the BinaryTreeNode class structure

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int> *> q;
    vector<int> v;
    if (!root)
        return v;
    q.push(root);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        v.push_back(t->val);
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
    return v;
}