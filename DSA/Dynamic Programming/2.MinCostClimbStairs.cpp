#include<iostream>
#include<vector>

using namespace std;

int minCost(vector<int>& cost, vector<int>& dp)
{}

int minCostClimbingStairs(vector<int>& cost)
{
    int ans;
    vector<int> dp(cost.size());

    ans = minCost(cost, dp);

    return -1;
}

int main()
{
    vector<int> data = {1,100,1,1,1,100,1,1,100,1};
    int res = minCostClimbingStairs(data);
    cout<<"Minimum Cost to Climb to the Top: "<<res<<endl;

    return 0;
}