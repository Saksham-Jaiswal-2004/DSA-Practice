#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    int start = 1;
    int end = nums.size() - 2;
    int middle;

    if(nums[0] != nums[1])
    return nums[0];

    if(nums[end+1] != nums[end])
    return nums[end+1];

    while (start <= end)
    {
        middle = start + (end - start) / 2;

        if(nums[middle] == nums[middle+1] || nums[middle] == nums[middle-1])
        {
            if(nums[middle] == nums[middle+1] && middle%2 == 0)
            start = middle + 2;
            else if(nums[middle] == nums[middle-1] && middle%2 != 0)
            start = middle + 1;
            else
            end = middle - 1;
        }
        else
        return nums[middle];
    }

    return -1;
}

int main()
{
    vector<int> data = {3,3,7,7,10,11,11};

    for (int i : data)
        cout << i << ", ";
    cout << endl
         << endl;

    cout << "Single Element in Array: " << singleNonDuplicate(data) << endl;

    return 0;
}

// 540. Single Element in a Sorted Array
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// My approach
// So if nums[middle] is the first one in its pair so it should be at an even index with respect to
// 0 indexed start position or if it is the second then it should be at an odd index so that the
// left side is correct else right side is correct and the other part contains that single element
// if there are no same element as nums[middle] then that is that single element

// More Optimised approach
// If the control is on an even index and that is the first element of pair then we are on the left side
// of the single element and if the control is on an odd index and its the first element of the pair then
// we are on the right side of the single element