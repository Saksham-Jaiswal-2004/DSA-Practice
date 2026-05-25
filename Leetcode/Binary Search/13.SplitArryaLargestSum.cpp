#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int countPartitions(vector<int> nums, int m)
{
    int elements = 1;
    long long elementsPartition = 0;
    for (int i=0 ; i<nums.size() ; i++)
    {
        if(elementsPartition + nums[i] <= m)
        elementsPartition += nums[i];
        else
        {
            elements++;
            elementsPartition = nums[i];
        }
    }

    return elements;
}

int splitArray(vector<int>& nums, int k)
{
    if(k > nums.size())
    return -1;

    int start = *max_element(nums.begin(), nums.end());
    int end = accumulate(nums.begin(), nums.end(), 0);
    int middle;

    while(start <= end)
    {
        middle = start + (end-start)/2;

        if(countPartitions(nums, middle) > k)
        start = middle + 1;
        else
        end = middle - 1;
    }

    return start;
}

int main()
{
    vector<int> data = {7,2,5,10,8};
    int k = 2;

    for(int i: data)
    cout<<i<<", ";
    cout<<"\nNumber of subarrays: "<<k<<endl<<endl;

    cout<<"Largest Sum of minimized subarray: "<<splitArray(data, k)<<endl;

    return 0;
}

// 410. Split Array Largest Sum
// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum 
// of any subarray is minimized
// Return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.