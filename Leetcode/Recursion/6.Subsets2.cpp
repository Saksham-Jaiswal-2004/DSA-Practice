#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void solve(int index, vector<int> &nums, vector<int> &path, vector<vector<int>> &ans)
{
    ans.push_back(path);

    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
        continue;

        path.push_back(nums[i]);
        solve(i + 1, nums, path, ans);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> path;

    solve(0, nums, path, ans);

    return ans;
}

int main()
{
    vector<int> data = {1, 2, 2, 3, 3};

    cout << "Original Array: ";
    for (int i : data)
        cout << i << ", ";

    cout << "\nSubsets" << endl;
    for (vector<int> j : subsetsWithDup(data))
    {
        cout << "[";
        for (int k : j)
            cout << k << ", ";
        cout << "]";

        cout << endl;
    }

    return 0;
}

// 90. Subsets II
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]