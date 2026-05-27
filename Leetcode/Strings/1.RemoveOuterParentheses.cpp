#include<iostream>
#include<stack>

using namespace std;

string removeOuterParentheses(string s)
{
    if(s.size() == 0)
    return s;

    stack<char> store;
    string ans = "";

    for(char c: s)
    {
        if(c == '(')
        {
            if(store.empty())
            store.push(c);
            else
            {
                ans += c;
                store.push(c);
            }
        }
        else
        {
            if(store.size() == 1)
            store.pop();
            else
            {
                ans += c;
                store.pop();
            }
        }
    }

    return ans;
}

int main()
{
    string data = "(()())(())(()(()))";

    cout<<"Original: "<<data<<endl;
    cout<<"After Removal: "<<removeOuterParentheses(data)<<endl;

    return 0;
}

// 1021. Remove Outermost Parentheses
// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses
// strings, and + represents string concatenation.
// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into 
// s = A + B, with A and B nonempty valid parentheses strings.
// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are 
// primitive valid parentheses strings.
// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

// Example 1:

// Input: s = "(()())(())"
// Output: "()()()"
// Explanation: 
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
// Example 2:

// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation: 
// The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
// After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
// Example 3:

// Input: s = "()()"
// Output: ""
// Explanation: 
// The input string is "()()", with primitive decomposition "()" + "()".
// After removing outer parentheses of each part, this is "" + "" = "".