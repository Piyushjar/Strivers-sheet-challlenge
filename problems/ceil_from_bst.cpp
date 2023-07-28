#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure:

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

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    int res = -1;
    while (root)
    {
        if (root->data == x)
            return x;
        if (root->data > x)
        {
            res = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }
    return res;
}