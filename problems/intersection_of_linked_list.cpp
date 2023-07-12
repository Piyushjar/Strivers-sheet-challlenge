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

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *first = firstHead, *second = secondHead;
    int fn = 0, sn = 0;
    while (first)
    {
        fn++;
        first = first->next;
    }
    while (second)
    {
        sn++;
        second = second->next;
    }
    first = firstHead, second = secondHead;
    int diff = abs(fn - sn);
    if (fn >= sn)
    {
        while (diff--)
        {
            first = first->next;
        }
    }
    else
    {
        while (diff--)
        {
            second = second->next;
        }
    }

    while (first && second)
    {
        if (first == second)
            return first;
        first = first->next;
        second = second->next;
    }
    return NULL;
}
