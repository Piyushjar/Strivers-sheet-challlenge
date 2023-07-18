#include <bits/stdc++.h>
using namespace std;

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

LinkedListNode<int> *reverseList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr = head, *nextn = NULL, *prevn = NULL;
    while (curr)
    {
        nextn = curr->next;
        curr->next = prevn;
        prevn = curr;
        curr = nextn;
    }
    return prevn;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedListNode<int> *right = reverseList(slow);
    LinkedListNode<int> *left = head;
    while (right)
    {
        if (right->data != left->data)
            return false;
        right = right->next;
        left = left->next;
    }
    return true;
}