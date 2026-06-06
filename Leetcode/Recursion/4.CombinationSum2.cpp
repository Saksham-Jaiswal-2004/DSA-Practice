#include<iostream>
#include<vector>
#include<algorithm>

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
    comboSum(index + 1, candidates, target - candidates[index], path, ans);

    path.pop_back();

    int next = index + 1;

    while(next < candidates.size() && candidates[next] == candidates[index])
    {
        next++;
    }

    comboSum(next, candidates, target, path, ans);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> path;

    comboSum(0, candidates, target, path, ans);

    return ans;
}

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    cout << "Array: ";
    for (int i : candidates)
        cout << i << ", ";
    cout << "\nTarget: " << target << endl;

    cout << "\nPossible Combinations: " << endl;
    for (vector<int> i : combinationSum2(candidates, target))
    {
        for (int j : i)
            cout << j << ", ";
        cout << endl;
    }

    return 0;
}

// 40. Combination Sum II
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations 
// in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]