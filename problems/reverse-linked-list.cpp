#include <bits/stdc++.h>

// ****************************************************************

// Following is the class structure of the LinkedListNode class:

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// ****************************************************************

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    LinkedListNode<int> *curr = head, *prevn = NULL, *nextn = NULL;
    while (curr)
    {
        nextn = curr->next;
        curr->next = prevn;
        prevn = curr;
        curr = nextn;
    }
    return prevn;
}