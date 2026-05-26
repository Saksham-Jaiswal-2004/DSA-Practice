#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
    swap(nums1, nums2);

    int n1 = nums1.size();
    int n2 = nums2.size();

    int start = 0;
    int end = n1;

    int leftSize = (n1 + n2 + 1) / 2;

    while (start <= end)
    {
        int partition1 = start + (end - start) / 2;
        int partition2 = leftSize - partition1;

        int l1 = (partition1 == 0) ? INT32_MIN : nums1[partition1 - 1];
        int r1 = (partition1 == n1) ? INT32_MAX : nums1[partition1];

        int l2 = (partition2 == 0) ? INT32_MIN : nums2[partition2 - 1];
        int r2 = (partition2 == n2) ? INT32_MAX : nums2[partition2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1 + n2) % 2 == 1)
            return max(l1, l2);

            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
        end = partition1 - 1;
        else
        start = partition1 + 1;
    }

    return 0.0;
}

int main()
{
    vector<int> data1 = {1, 2};
    vector<int> data2 = {3, 4};

    for (int i : data1)
        cout << i << ", ";
    cout << endl;
    for (int i : data2)
        cout << i << ", ";
    cout << endl;

    cout << "\nMedian of both arrays combined: " << findMedianSortedArrays(data1, data2) << endl;

    return 0;
}

// 4. Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.