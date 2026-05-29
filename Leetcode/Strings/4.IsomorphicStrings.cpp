#include<iostream>
#include<unordered_map>

using namespace std;

bool isIsomorphic(string s, string t)
{
    if(s.length() != t.length())
    return false;

    unordered_map<char, char> iso;
    unordered_map<char, char> iso2;
    string ans = "";

    for(int i=0 ; i<s.length() ; i++)
    {
        if(iso.count(s[i]) == 0 && iso2.count(t[i]) == 0)
        {
            iso[s[i]] = t[i];
            iso2[t[i]] = s[i];
        }
    }

    for(char c: s)
    ans += iso[c];

    if(ans == t)
    return true;
    else
    return false;
}

int main()
{
    string s1 = "paper";
    string s2 = "title";

    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Is Isomorphic? "<<isIsomorphic(s1, s2)<<endl;

    return 0;
}

// 205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. 
// No two characters may map to the same character, but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "f11", t = "b23"
// Output: false
// Explanation:
// The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

// Example 3:
// Input: s = "paper", t = "title"
// Output: true