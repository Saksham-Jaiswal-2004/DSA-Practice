// 2D DP
#include<iostream>
#include<vector>

using namespace std;

// Recursion
int solve(int n, vector<vector<int>>& points, int invalid)
{
    // Base Case
    if(n==0)
    {
        int merit=0;
        for(int i=0 ; i<3 ; i++)
        {
            if(i!=invalid)
            merit = max(merit, points[0][i]);
        }
        return merit;
    }

    int merit1 = -1;
    int merit2 = -1;
    for(int i=0 ; i<3 ; i++)
    {
        if(i != invalid && merit1 == -1)
        merit1 = points[n][i] + solve(n-1, points, i);
        if(i != invalid && merit1 != -1)
        merit2 = points[n][i] + solve(n-1, points, i);
    }

    return max(merit1, merit2);
}

// Recursion + Memoisation
int solve2(int n, vector<vector<int>>& points, int invalid, vector<int>& dp)
{
    // Base Case
    if(n==0)
    {
        int merit=0;
        for(int i=0 ; i<3 ; i++)
        {
            if(i!=invalid)
            merit = max(merit, points[0][i]);
        }
        dp[n] = merit;
        return dp[n];
    }

    if(dp[n] != -1)
    return dp[n];

    int merit1 = -1;
    int merit2 = -1;
    int merit3 = -1;
    for(int i=0 ; i<3 ; i++)
    {
        if(i != invalid && merit1 == -1)
        merit1 = points[n][i] + solve2(n-1, points, i, dp);
        if(i != invalid && merit1 != -1 && merit2 == -1)
        merit2 = points[n][i] + solve2(n-1, points, i, dp);
        if(i != invalid && merit1 != -1 && merit2 != -1)
        merit3 = points[n][i] + solve2(n-1, points, i, dp);
    }

    dp[n] = max(merit1, merit2);
    dp[n] = max(dp[n], merit3);

    return dp[n];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(n+1, -1);
    // return solve(n-1, points, -1);
    return solve2(n-1, points, -1, dp);
}

int main()
{
    vector<vector<int>> data = {{1,2,5}, {3 ,1 ,1} ,{3,3,3}};
    int res = ninjaTraining(data[0].size(), data);
    cout<<"Maximum Merit Points Ninja can earn: "<<res<<endl;

    return 0;
}

// Ninja’s Training (2D DP)

// Problem statement
// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three 
// activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each 
// day. As Ninja has to improve all his skills, he can't do the same activity in two consecutive days. Can you 
// help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
// Your task is to calculate the maximum number of merit points that Ninja can earn.

// For Example
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 100000.
// 1 <= values of POINTS arrays <= 100 .

// Time limit: 1 sec
// Sample Input 1:
// 2
// 3
// 1 2 5 
// 3 1 1
// 3 3 3
// 3
// 10 40 70
// 20 50 80
// 30 60 90
// Sample Output 1:
// 11
// 210
// Explanation of sample input 1:
// For the first test case,
// One of the answers can be:
// On the first day, Ninja will learn new moves and earn 5 merit points. 
// On the second day, Ninja will do running and earn 3 merit points. 
// On the third day, Ninja will do fighting and earn 3 merit points. 
// The total merit point is 11 which is the maximum. 
// Hence, the answer is 11.

// For the second test case:
// One of the answers can be:
// On the first day, Ninja will learn new moves and earn 70 merit points. 
// On the second day, Ninja will do fighting and earn 50 merit points. 
// On the third day, Ninja will learn new moves and earn 90 merit points. 
// The total merit point is 210 which is the maximum. 
// Hence, the answer is 210.
// Sample Input 2:
// 2
// 3
// 18 11 19
// 4 13 7
// 1 8 13
// 2
// 10 50 1
// 5 100 11
// Sample Output 2:
// 45
// 110