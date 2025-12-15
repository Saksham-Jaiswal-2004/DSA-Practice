#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// Recursion
int solve(vector<int>& coins, int amount)
{
    if(amount == 0)
    return 0;
    if(amount < 0)
    return INT_MAX;

    int mini = INT_MAX;
    for(int i=0 ; i<coins.size() ; i++)
    {
        int ans = solve(coins, amount-coins[i]);

        if(ans != INT_MAX)
        mini = min(mini, 1+ans);
    }

    return mini;
}

// Recursion + Memoisation
int solve2(vector<int>& coins, int amount, vector<int>& dp)
{
    if(amount == 0)
    return 0;
    if(amount < 0)
    return INT_MAX;

    if(dp[amount] != -1)
    return dp[amount];

    int mini = INT_MAX;
    for(int i=0 ; i<coins.size() ; i++)
    {
        int ans = solve2(coins, amount-coins[i], dp);

        if(ans != INT_MAX)
        mini = min(mini, 1+ans);
    }

    dp[amount] = mini;

    return mini;
}

// Tabulation
int solve3(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for(int i=1 ; i<=amount ; i++)
    {
        for(int j=0 ; j<coins.size() ; j++)
        {
            if(i-coins[j] >= 0  && dp[i-coins[j]] != INT_MAX)
            dp[i] = min(dp[i], 1+dp[i-coins[j]]);
        }
    }

    if(dp[amount] == INT_MAX)
    return -1;

    return dp[amount];
}

int coinChange(vector<int>& coins, int amount)
{
    // vector<int> dp(amount+1, -1);
    int ans = solve3(coins, amount);

    if(ans == INT_MAX)
    return -1;

    return ans;
}

int main()
{
    vector<int> data = {1,3,4};
    int amount = 6;

    cout<<"Given Options: ";
    for(int i: data)
    cout<<i<<" ";

    int res = coinChange(data, amount);
    cout<<"\nMinimum coins to make "<<amount<<": "<<res<<endl;

    return 0;
}

// 322. Coin Change
// You are given an integer array coins representing coins of different denominations and an integer amount
// representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be 
// made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0