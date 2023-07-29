#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int num)
{
    if (st.empty() || st.top() <= num)
    {
        st.push(num);
        return;
    }
    int n = st.top();
    st.pop();
    insertAtBottom(st, num);
    st.push(n);
}

void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    insertAtBottom(stack, num);
}