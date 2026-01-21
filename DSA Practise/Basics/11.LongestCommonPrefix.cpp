#include<iostream>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    int len = strs.size();
    int j = 0;
    bool flag = true;
    string res = "";

    while(flag)
    {
        char c;
        if(strs[0][j])
        c = strs[0][j];
        else
        break;

        for(int i=1 ; i<len ; i++)
        {
            if(c != strs[i][j] || !strs[i][j])
            {
                flag = false;
                break;
            }
        }
        if (flag != false)
        res += c;
        j++;
    }

    return res;
}

int main()
{
    vector<string> data = {"dog","dracecar","dcar"};
    cout<<"Longest Common Prefix: "<<longestCommonPrefix(data)<<endl;

    return 0;
}

// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.