#include <bits/stdc++.h>
using namespace std;

// ----------------- Binary Tree node class for reference -----------------
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void connectNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();
            if (i == size - 1)
                curr->next = NULL;
            else
                curr->next = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}