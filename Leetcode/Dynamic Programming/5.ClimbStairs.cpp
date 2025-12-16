#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

int solve(int nStairs, int i, vector<int>& dp)
{
    if (i == nStairs) 
    return 1;

    if (i > nStairs) 
    return 0;

    if (dp[i] != -1) 
    return dp[i];

    dp[i] = (solve(nStairs, i + 1, dp) + solve(nStairs, i + 2, dp)) % MOD;

    return dp[i];
}

int countDistinctWays(int nStairs)
{
    vector<int> dp(nStairs, -1);
    return solve(nStairs, 0, dp);
}

int main()
{
    int data = 3;
    int res = countDistinctWays(data);
    cout<<"Number of ways to climb to "<<data<<": "<<res;

    return 0;
}

// Leetcode
// 70. Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Coding Ninjas
// Problem statement
// You have been given a number of stairs. Initially, you are at the 0th stair, 
// and you need to reach the Nth stair.

// Each time, you can climb either one step or two steps.

// You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

// Note:

// Note: Since the number of ways can be very large, return the answer modulo 1000000007.
// Example :
// N=3
// We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first two-step and 
// then one step i.e. {(0,2),(1, 3)} or we can climb first one step and then two step i.e. {(0,1), (1,3)}.