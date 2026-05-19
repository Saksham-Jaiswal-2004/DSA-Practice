#include<iostream>
#include<vector>

using namespace std;

int findPeakElement(vector<int>& nums)
{
    if(nums.size() < 1)
    return -1;

    if(nums.size() == 1)
    return 0;

    int start = 1;
    int end = nums.size()-2;
    int middle;

    if(nums[0]>nums[1])
    return 0;

    if(nums[end+1]>nums[end])
    return end+1;

    while(start <= end)
    {
        middle = start + (end-start)/2;

        if(nums[middle]<nums[middle-1] || nums[middle]<nums[middle+1])
        {
            if(nums[middle]<nums[middle+1])
            start = middle +1;
            else
            end = middle -1;
        }
        else
        return middle;
    }
    
    return -1;
}

int main()
{
    vector<int> data = {1,2,1,3,5,6,4};

    for(int i: data)
    cout<<i<<", ";
    cout<<endl<<endl;

    cout<<"Peak Element is at: "<<findPeakElement(data)<<endl;
    cout<<"Peak Element Value: "<<data[findPeakElement(data)]<<endl;

    return 0;
}

// 162. Find Peak Element
// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

// My Approach:
// Check the middle element for peak element, if not then check if its an increasing slope
// (i.e. right element is bigger) 
// then peak in the right side and for decreasing slope (i.e. left element is bigger) in the left side.