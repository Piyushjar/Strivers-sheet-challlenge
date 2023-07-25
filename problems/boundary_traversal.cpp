#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void leftTraversal(TreeNode<int> *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);

    if (root->left)
        leftTraversal(root->left, ans);
    else
        leftTraversal(root->right, ans);
}

void leafTraversal(TreeNode<int> *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

void rightTraversal(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        rightTraversal(root->right, ans);
    else
        rightTraversal(root->left, ans);

    // wapas jate waqt print data
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);
    // left Traversal
    leftTraversal(root->left, ans);
    // traversal leaf node
    // leaf node in left subtree
    leafTraversal(root->left, ans);
    // leaf node in right subtree
    leafTraversal(root->right, ans);
    // Traverse right part
    rightTraversal(root->right, ans);

    return ans;
}