#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> res;
    if (!root)
        return res;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool rev = false;
    stack<int> st;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *t = q.front();
            q.pop();

            rev ? st.push(t->data) : res.push_back(t->data);

            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        if (rev)
        {
            while (!st.empty())
            {
                res.push_back(st.top());
                st.pop();
            }
        }
        rev = !rev;
    }
    return res;
}
