#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr)
{
    int diff, min=INT16_MAX;
    vector<vector<int>> res;
    int size = arr.size();
    sort(arr.begin(), arr.end());

    for(int i=1 ; i<size ; i++)
    {
        diff = arr[i] - arr[i-1];

        if(diff == min)
        res.push_back({arr[i-1], arr[i]});
        else if(diff < min)
        {
            min = diff;
            res.clear();
            res.push_back({arr[i-1], arr[i]});
        }
    }

    return res;
}

int main()
{
    vector<int> data = {40,11,26,27,-20};
    vector<vector<int>> ans = minimumAbsDifference(data);

    for(vector<int> i: ans)
    {
        for(int j: i)
        {
            cout<<j<<", ";
        }
        cout<<endl;
    }

    return 0;
}

// 1200. Minimum Absolute Difference
// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr

// Example 1:

// Input: arr = [4,2,1,3]
// Output: [[1,2],[2,3],[3,4]]
// Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
// Example 2:

// Input: arr = [1,3,6,10,15]
// Output: [[1,3]]
// Example 3:

// Input: arr = [3,8,-10,23,19,-4,-14,27]
// Output: [[-14,-10],[19,23],[23,27]]