#include <bits/stdc++.h>
using namespace std;
// Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLeftView(TreeNode<int> *root)
{
    // Write your code here
    queue<TreeNode<int> *> q;
    vector<int> v;
    if (!root)
        return v;
    int res = 0;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto t = q.front();
            q.pop();
            if (i == 0)
                v.push_back(t->data);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return v;
}