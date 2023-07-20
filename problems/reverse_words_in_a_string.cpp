#include <bits/stdc++.h>
using namespace std;

string reverseString(string &str)
{
    // Write your code here.
    string res = "";
    stringstream ss(str);
    string word;
    stack<string> st;
    while (ss >> word)
    {
        st.push(word);
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
        res += " ";
    }
    res.pop_back();
    return res;
}