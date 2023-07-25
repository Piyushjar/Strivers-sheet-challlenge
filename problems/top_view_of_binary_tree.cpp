#include <bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure:

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    if (!root)
        return res;
    map<int, int> m;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode<int> *curr = p.first;
        int idx = p.second;
        if (m.find(idx) == m.end())
            m[idx] = curr->val;
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