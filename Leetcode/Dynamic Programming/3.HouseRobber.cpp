#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &nums, int n)
{
    if(n<0)
      return 0;
    if(n==0)
      return nums[0];

    int include = solve(nums, n-2) + nums[n];
    int exclude = solve(nums, n-1) + 0;

    return max(include, exclude);
}

int rob(vector<int>& nums)
{
    int len = nums.size();
    int res = solve(nums, len-1);

    return res;
}

// Optimised Solution
// int solve(vector<int> &nums, int n, vector<int> &dp) 
// {
//     if(n < 0) 
//       return 0;
//     if(n == 0)
//       return nums[0];

//     if(dp[n] != -1) 
//       return dp[n];

//     int include = nums[n] + solve(nums, n - 2, dp);
//     int exclude = solve(nums, n - 1, dp);

//     return dp[n] = max(include, exclude);
// }

// int rob(vector<int>& nums) 
// {
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return solve(nums, n - 1, dp);
// }

int main()
{
    vector<int> data = {2,1,1,2};
    int ans = rob(data);
    cout<<"Maximum Amount: "<<ans<<endl;

    return 0;
}

// Leetcode
// 198. House Robber
// Medium

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.