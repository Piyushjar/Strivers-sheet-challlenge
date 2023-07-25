#include <bits/stdc++.h>
using namespace std;
// Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> res;
    if (!root)
        return res;
    map<int, vector<int>> m;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode<int> *curr = p.first;
        int idx = p.second;
        m[idx].push_back(curr->data);
        if (curr->left)
            q.push({curr->left, idx - 1});
        if (curr->right)
            q.push({curr->right, idx + 1});
    }
    for (auto it : m)
    {
        for (int i : it.second)
            res.push_back(i);
    }
    return res;
}
