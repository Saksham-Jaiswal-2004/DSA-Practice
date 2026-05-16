#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int middle;

    while(start <= end)
    {
        middle = start + (end-start)/2;
        if(nums[middle] == target)
        return middle;

        if(nums[start] <= nums[middle])
        {
            if(nums[start] <= target && nums[middle] >= target)
            end = middle - 1;
            else
            start = middle + 1;
        }
        else
        {
            if(nums[middle] <= target && nums[end] >= target)
            start = middle + 1;
            else
            end = middle - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> data = {4,5,6,7,0,1,2,3};
    int target;

    for(int i: data)
    cout<<i<<", ";

    cout<<endl<<endl;

    cout<<"Enter Target: ";
    cin>>target;

    cout<<"Target is at index: "<<search(data, target)<<endl;

    return 0;
}

// 33. Search in Rotated Sorted Array
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1