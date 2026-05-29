#include<iostream>
#include<list>

using namespace std;

bool isAnagram(string s, string t)
{
    if(s.length() != t.length())
    return false;

    list<char> l1(s.begin(), s.end());
    list<char> l2(t.begin(), t.end());

    l1.sort();
    l2.sort();

    return l1 == l2;
}

int main()
{
    string s1 = "rbc";
    string s2 = "car";

    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;

    cout<<"Is Anagram: "<<isAnagram(s1, s2)<<endl;

    return 0;
}

// 242. Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false