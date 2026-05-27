#include<iostream>

using namespace std;

string reverseWords(string s)
{
    if(s.size() <= 1)
    return s;

    string ans = "";
    int st = -1;

    for(int i=s.size()-1 ; i>=0 ; i--)
    {
        if(s[i] != ' ')
        {
            if(st == -1)
            {
                st = i;

                if(!ans.empty())
                ans += " ";
            }

            if(i == 0)
            {
                if(st == s.size()-1)
                ans = ans + s.substr(i);
                else
                ans = ans + s.substr(i, st-i+1);
            }
        }
        else
        {
            if(st != -1)
            {
                if(st == s.size()-1)
                ans = ans + s.substr(i+1);
                else
                ans = ans + s.substr(i+1, st-i);
                st = -1;
            }
        }
    }

    return ans;
}

int main()
{
    string data = "  the sky is blue  ";

    cout<<"Original: "<<data<<endl;
    cout<<"Reversed: "<<reverseWords(data)<<endl;

    return 0;
}

// 151. Reverse Words in a String
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string 
// should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.