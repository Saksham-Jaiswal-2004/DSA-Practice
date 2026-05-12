#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) 
        return mid;
        if (nums[mid] < target) 
        low = mid + 1;
        else 
        high = mid - 1;
    }

    return low;
}

int main()
{
    vector<int> data = {1,3,5,6};
    int target;

    for(int i: data)
        cout<<i<<" ";

    cout<<endl;

    cout<<"Enter Target: ";
    if(!(cin>>target)) return 0;

    cout<<"Index: "<<searchInsert(data, target)<<endl;

    return 0;
}

// 35. Search Insert Position
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4