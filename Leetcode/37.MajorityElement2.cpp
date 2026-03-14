#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
    int len = nums.size();
    int n = len/3;
    vector<int> ans;
    unordered_map<int, int> count;

    for(int i=0 ; i<len ; i++)
    count[nums[i]]++;

    for(const auto& i: count)
    {
        if(i.second > n)
        ans.push_back(i.first);
    }

    return ans;
}

int main()
{
    vector<int> data = {3,2,3};

    vector<int> res = majorityElement(data);
    cout<<"All elements appearing more than "<<data.size()/3<<" time(s):"<<endl;
    for(int i: res)
    cout<<i<<", ";

    return 0;
}

// 229. Majority Element II
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]