#include<iostream>

using namespace std;

bool rotateString(string s, string goal)
{
    if(s.length() != goal.length())
    return false;

    string doubled = s + s;

    return doubled.find(goal) != string::npos;
}

int main()
{
    string s1 = "defdefdefabcabc";
    string s2 = "defdefabcabcdef";

    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;

    cout<<"Is Same after Rotations: "<<rotateString(s1, s2)<<endl;

    return 0;
}

// 796. Rotate String
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
 
// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false