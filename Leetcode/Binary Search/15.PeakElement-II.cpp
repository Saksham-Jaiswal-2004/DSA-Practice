#include<iostream>
#include<vector>

using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat)
{
    int m = mat.size();
    int n = mat[0].size();

    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int maxRow = 0;
        for (int i = 1; i < m; i++)
        {
            if (mat[i][mid] > mat[maxRow][mid])
            maxRow = i;
        }

        int leftVal = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
        int rightVal = (mid + 1 < n) ? mat[maxRow][mid + 1] : -1;

        if (mat[maxRow][mid] > leftVal && mat[maxRow][mid] > rightVal)
        return {maxRow, mid};

        if (leftVal > mat[maxRow][mid])
        end = mid - 1;
        else
        start = mid + 1;
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> data = {{70,50,40,30,20}, {100,1,2,3,4}};

    for(vector<int> i: data)
    {
        for(int j: i)
        cout<<j<<" ";
        cout<<endl;
    }

    vector<int> ans = findPeakGrid(data);
    cout<<"Peak Element Index: ["<<ans[0]<<", "<<ans[1]<<"]"<<endl;;

    return 0;
}

// 1901. Find a Peak Element II
// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the 
// left, right, top, and bottom.
// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and 
// return the length 2 array [i,j].
// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time. 

// Example 1:

// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
// Example 2:

// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.