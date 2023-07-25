#include <bits/stdc++.h>
using namespace std;
// Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    vector<int> res;
    if (!root)
        return res;
    map<int, int> m;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        BinaryTreeNode<int> *curr = p.first;
        int idx = p.second;
        m[idx] = curr->data;
        if (curr->left)
            q.push({curr->left, idx - 1});
        if (curr->right)
            q.push({curr->right, idx + 1});
    }
    for (auto it : m)
    {
        res.push_back(it.second);
    }
    return res;
}
