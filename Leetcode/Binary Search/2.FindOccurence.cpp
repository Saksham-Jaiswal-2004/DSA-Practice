#include<iostream>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> res(2,-1);
    int start = 0, end = nums.size()-1;
    int mid2 = -1, end2 = -1;

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(target<nums[mid])
        end = mid-1;
        else if(target>nums[mid])
        start = mid+1;
        else
        {
            if(mid2 == -1)
            mid2 = mid;
            if(end2 == -1)
            end2 = end;

            if(res[1] == -1)
            res[1] = mid;

            if(res[0]==-1 || res[0]>mid)
            res[0] = mid;

            end = mid-1;
        }
    }

    if(mid2 == -1)
        return res;

    start = mid2;
    end = end2;

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(target<nums[mid])
        end = mid-1;
        else if(target>nums[mid])
        start = mid+1;
        else
        {
            if(res[1]==-1 || res[1]<mid)
            res[1] = mid;

            start = mid+1;
        }
    }

    return res;
}

int main()
{
    vector<int> data = {7,7,8,8,10,10};
    int target;

    for(int i: data)
    cout<<i<<" ";
    cout<<endl;

    cout<<"Enter Target: ";
    cin>>target;

    vector<int> ans = searchRange(data, target);
    cout<<"["<<ans[0]<<", "<<ans[1]<<"]"<<endl;

    return 0;
}

// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]