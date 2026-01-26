#include<iostream>
#include<vector>

using namespace std;

int binSearch(vector<int>& nums, int target, int start, int end)
{
    int mid = start + ((end-start)/2);

    if(nums[mid] == target)
    return mid;

    while(start<end)
    {
        if(nums[mid]<target)
        return binSearch(nums, target, mid+1, end);
        else if(nums[mid] == target)
        return mid;
        else
        return binSearch(nums, target, start, mid-1);
    }

    return -1;
}

int search(vector<int>& nums, int target)
{ 
    int res = binSearch(nums, target, 0, nums.size()-1);
    return res;
}

int main()
{
    vector<int> data = {2, 5};
    int target = 5;
    int ans = search(data, target);

    if(ans!=-1)
    cout<<target<<" is present at index "<<ans<<endl;
    else
    cout<<target<<" is not present in the given set"<<endl;

    return 0;
}

// 704. Binary Search
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1