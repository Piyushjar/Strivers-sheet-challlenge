
#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *rotate(Node *head, int k)
{
    // Write your code here.
    if (!head)
        return NULL;
    int n = 1;
    Node *curr = head;
    while (curr->next)
    {
        curr = curr->next;
        n++;
    }
    if (k % n == 0)
        return head;
    k = n - (k % n);
    curr->next = head;
    while (k--)
    {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
}