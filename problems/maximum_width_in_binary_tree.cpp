#include <bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    queue<TreeNode<int> *> q;
    if (!root)
        return 0;
    int res = 0;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        res = max(res, s);
        for (int i = 0; i < s; i++)
        {
            auto t = q.front();
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return res;
}