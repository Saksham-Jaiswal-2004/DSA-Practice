#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void makeCombos(vector<string> &ans, string& path, int index, string digits, unordered_map<char, vector<char>>& mapping)
{
    if (index >= digits.size())
        return;

    if (index == digits.size()-1)
    {
        for (char a : mapping[digits[index]])
        {
            string p = path + a;
            ans.push_back(p);
        }

        return;
    }

    for (char a : mapping[digits[index]])
    {
        string p = path + a;
        makeCombos(ans, p, index+1, digits, mapping);
    }
}

vector<string> letterCombinations(string digits)
{
    unordered_map<char, vector<char>> mapping;
    mapping['2'] = {'a', 'b', 'c'};
    mapping['3'] = {'d', 'e', 'f'};
    mapping['4'] = {'g', 'h', 'i'};
    mapping['5'] = {'j', 'k', 'l'};
    mapping['6'] = {'m', 'n', 'o'};
    mapping['7'] = {'p', 'q', 'r', 's'};
    mapping['8'] = {'t', 'u', 'v'};
    mapping['9'] = {'w', 'x', 'y', 'z'};

    vector<string> ans;
    string path;

    makeCombos(ans, path, 0, digits, mapping);

    return ans;
}

int main()
{
    string num = "23";

    cout << "Number: " << num << endl;

    cout << "Possible Combinations" << endl;
    for (string s : letterCombinations(num))
        cout << s << endl;

    return 0;
}

// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number
// could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map
// to any letters.

// 2 - abc
// 3 - def
// 4 - ghi
// 5 - jkl
// 6 - mno
// 7 - pqrs
// 8 - tuv
// 9 - wxyz

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]