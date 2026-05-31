#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int maxDepth(string s)
{
    if(s.length() < 2)
    return 0;

    stack<char> st;
    int ans = 0;

    for(char c: s)
    {
        if(c == '(')
        {
            st.push(c);
            ans = max(ans, int(st.size()));
        }
        else if(c == ')')
        {
            st.pop();
        }
    }

    return ans;
}

int main()
{
    string data = "(1+(2*3)+((8)/4))+1";
    // string data = "(((()(()))))";

    cout<<"String: "<<data<<endl;
    cout<<"Parentheses Nesting Depth: "<<maxDepth(data)<<endl;

    return 0;
}

// 1614. Maximum Nesting Depth of the Parentheses
// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of 
// nested parentheses.

// Example 1:
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation:
// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:
// Input: s = "(1)+((2))+(((3)))"
// Output: 3
// Explanation:
// Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:
// Input: s = "()(())((()()))"
// Output: 3