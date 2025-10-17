#include<iostream>
#include<vector>

using namespace std;

int fb(int n, vector<int>&dp)
{
    if(n<=1)
        return n;

    if(dp[n]!=-1)
    return dp[n];

    dp[n] = fb(n-1, dp)+fb(n-2, dp);
    return dp[n];
}
int fib(int n) 
{
    vector<int> dp(n+1);
    for(int i=0 ; i<=n ; i++)
    {
        dp[i]=-1;
    }

    return fb(n, dp);
}

int main()
{
    cout<<fib(3)<<endl;
    
    return 0;
}