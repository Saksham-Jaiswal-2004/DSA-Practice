#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    int l = n-1;
    
    while(l > 2)
    {
        for (int i = 0; i < l; i++) 
        {
            if (i > 0 && nums[i] == nums[i-1]) 
            continue;
    
            int j = i + 1, k = l - 1;
            while (j < k) 
            {
                long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
    
                if (sum < target) 
                j++;
                else if (sum > target) 
                k--;
                else 
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
    
                    while (j < k && nums[j] == nums[j+1]) 
                    j++;
    
                    while (j < k && nums[k] == nums[k-1]) 
                    k--;
    
                    j++; k--;
                }
            }
        }
        l--;
        while(l > 2 && nums[l]==nums[l+1])
        l--;
    }

    return ans;
}

int main()
{
    vector<int> data = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> res = fourSum(data, target);

    cout<<"Number of Quadruplets with sum equal to "<<target<<": "<<res.size()<<endl;
    for(vector<int> i: res)
    {
        for(int j: i)
        cout<<j<<", ";

        cout<<endl;
    }
    
    return 0;
}

// 18. 4Sum
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]