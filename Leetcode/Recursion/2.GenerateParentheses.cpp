#include <iostream>
#include <vector>

using namespace std;

void solve(int open, int close, int n, string curr, vector<string> &ans)
{

    if (curr.size() == 2 * n)
    {
        ans.push_back(curr);
        return;
    }

    if (open < n)
        solve(open + 1, close, n, curr + '(', ans);

    if (close < open)
        solve(open, close + 1, n, curr + ')', ans);
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    solve(0, 0, n, "", ans);
    return ans;
}

int main()
{
    int n = 4;

    cout << "Count: " << n << endl;

    for (string paren : generateParenthesis(n))
        cout << paren << endl;

    return 0;
}

// 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]