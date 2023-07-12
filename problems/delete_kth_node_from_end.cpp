#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *removeKthNode(Node *head, int k)
{
    // Write your code here.
    int n = 0;
    Node *curr = head;
    while (curr)
    {
        n++;
        curr = curr->next;
    }
    int diff = n - k;
    if (diff == 0)
        return head->next;
    curr = head;
    while (diff > 1)
    {
        curr = curr->next;
        diff--;
    }
    Node *t = curr->next;
    curr->next = curr->next->next;
    delete (t);
    return head;
}
