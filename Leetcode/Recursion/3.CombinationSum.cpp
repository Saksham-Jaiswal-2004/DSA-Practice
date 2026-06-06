#include <iostream>
#include <vector>

using namespace std;

void comboSum(int index, vector<int> &candidates, int target, vector<int> &path, vector<vector<int>> &ans){
    if (target == 0)
    {
        ans.push_back(path);
        return;
    }

    if (index >= candidates.size() || target < 0)
        return;

    path.push_back(candidates[index]);
    comboSum(index, candidates, target - candidates[index], path, ans);

    path.pop_back();

    comboSum(index + 1, candidates, target, path, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> path;

    comboSum(0, candidates, target, path, ans);

    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    cout << "Array: ";
    for (int i : candidates)
        cout << i << ", ";
    cout << "\nTarget: " << target << endl;

    cout << "\nPossible Combinations: " << endl;
    for (vector<int> i : combinationSum(candidates, target))
    {
        for (int j : i)
            cout << j << ", ";
        cout << endl;
    }

    return 0;
}

// 39. Combination Sum
// Given an array of distinct integers candidates and a target integer target, return a list of all unique
// combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
// frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than
// 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []