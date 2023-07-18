#include <bits/stdc++.h>
using namespace std;

// Definition of linked list :

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *head = NULL, *prev = NULL;
    int carry = 0;
    while (num1 || num2)
    {
        int v1 = num1 ? num1->data : 0;
        int v2 = num2 ? num2->data : 0;
        int temp = v1 + v2 + carry;
        carry = temp / 10;
        int val = temp % 10;
        Node *curr = new Node(val);
        if (!head)
            head = curr;
        if (prev)
            prev->next = curr;
        prev = curr;
        num1 = num1 ? num1->next : NULL;
        num2 = num2 ? num2->next : NULL;
    }
    if (carry > 0)
    {
        Node *t = new Node(carry);
        prev->next = t;
    }
    return head;
}
