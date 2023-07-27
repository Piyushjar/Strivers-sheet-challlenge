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

int height(TreeNode<int> *root, int &res)
{
    if (!root)
        return 0;

    int left = height(root->left, res);
    int right = height(root->right, res);

    res = max(res, left + right);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    if (!root)
        return 0;
    int res = 0;
    height(root, res);
    return res;
}
