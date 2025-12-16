#include<iostream>
#include<vector>

using namespace std;

// Recursion
int solve(vector<int>& nums, int len)
{
    int sum=0;
    int start=0;
    int maxSum=0;

    if(start+len>nums.size())
    return 0;

    while(start + len <= nums.size())
    {
        for(int i=0 ; i<len ; i++)
        {
            sum += nums[start+i];
        }

        start += len;
        maxSum = max(maxSum, sum);
    }

    maxSum = max(maxSum, solve(nums, len+1));

    return maxSum;
}

// Recursion + Memoisation
int solve2(vector<int>& nums, int n, vector<int>& dp)
{
    if(n == 0)
    return dp[n] = nums[0];

    if(dp[n]!=-1)
    return dp[n];

    dp[n] = max(nums[n], nums[n] + solve2(nums, n - 1, dp));

    return dp[n];
}

int maxSubArray(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    for (int i = 0; i < n; i++)
        solve2(nums, i, dp);

    int ans=dp[0];
    for(int i: dp)
    ans = max(ans, i);

    return ans;
}

int main()
{
    vector<int> data = {5,4,-1,7,8};
    int res = maxSubArray(data);
    cout<<"Maximum Sum of Subarray: "<<res<<endl;

    return 0;
}

// 53. Maximum Subarray
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.