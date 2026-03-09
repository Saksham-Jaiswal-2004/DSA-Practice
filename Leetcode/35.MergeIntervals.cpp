#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    int n = intervals.size();

    if(n<2)
    return intervals;
    
    vector<vector<int>>ans;

    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) 
    {
        return a[0] < b[0];
    });

    for(int i=0 ; i<n ; i++)
    {
        int j=1;

        while(i+j<n && (intervals[i+j-1][1]>=intervals[i+j][0]))
        j++;

        ans.push_back({intervals[i][0], intervals[i+j-1][1]});
        i = i+j-1;
    }

    return ans;
}

vector<vector<int>> merge2(vector<vector<int>>& intervals)
{
    int n = intervals.size();

    if(n<2)
    return intervals;
    
    vector<vector<int>>ans;

    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) 
    {
        return a[0] < b[0];
    });

    for(auto &interval : intervals)
    {
        if(ans.empty() || ans.back()[1] < interval[0])
            ans.push_back(interval);
        else
            ans.back()[1] = max(ans.back()[1], interval[1]);
    }

    return ans;
}

int main()
{
    vector<vector<int>> data = {{1,3},{2,6},{5,10},{15,18}};
    vector<vector<int>> res = merge2(data);

    cout<<"Non-Overlapping Inervals"<<endl;
    for(vector<int> i: res)
    {
        for(int j: i)
        cout<<j<<" ";

        cout<<endl;
    }

    return 0;
}

// 56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// Example 3:

// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.