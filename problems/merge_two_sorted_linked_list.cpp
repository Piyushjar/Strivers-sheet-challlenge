#include <bits/stdc++.h>
using namespace std;

// Following is the linked list node structure.

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    Node<int> *newHead = new Node<int>(-1);
    Node<int> *curr = newHead;

    while (first && second)
    {
        if (first->data > second->data)
        {
            curr->next = second;
            curr = curr->next;
            second = second->next;
        }
        else
        {
            curr->next = first;
            curr = curr->next;
            first = first->next;
        }
    }

    if (first)
        curr->next = first;
    if (second)
        curr->next = second;

    return newHead->next;
}
