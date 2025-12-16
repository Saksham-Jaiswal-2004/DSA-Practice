#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &nums, int n, vector<int> &dp) 
{
    if(n < 0) 
      return 0;
    if(n == 0)
      return nums[0];

    if(dp[n] != -1) 
      return dp[n];

    int include = nums[n] + solve(nums, n - 2, dp);
    int exclude = solve(nums, n - 1, dp);

    return dp[n] = max(include, exclude);
}

int rob(vector<int>& nums) 
{
    if(nums.size() == 1)
      return nums[0];
    
    int n = nums.size();
    vector<int> dp1(n-1, -1), dp2(n-1, -1);

    vector<int> first, second;
    for(int i=0 ; i<n ; i++)
    {
        if(i!=0)
          first.push_back(nums[i]);
        if(i!=n-1)
          second.push_back(nums[i]);
    }

    return max(solve(first, n-2, dp1), solve(second, n-2, dp2));
}

int main()
{
    vector<int> data = {1,2,3,1};
    int ans = rob(data);
    cout<<"Maximum Amount: "<<ans<<endl;

    return 0;
}

// 213. House Robber II
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3