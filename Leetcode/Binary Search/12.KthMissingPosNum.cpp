#include<iostream>
#include<vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k)
{
    if(k < arr[0])
    return k;
    
    int start = 0;
    int end = arr.size()-1;
    int middle;

    while(start <= end)
    {
        middle = start + (end-start)/2;

        if((arr[middle] - (middle+1)) < k)
        start = middle + 1;
        else
        end = middle - 1;
    }

    return k + end + 1;
}

int main()
{
    vector<int> data = {2,3,4,7,11};
    int k = 5;

    for(int i: data)
    cout<<i<<", ";
    cout<<"\nKth Position: "<<k<<endl<<endl;

    cout<<"Kth Missing Number: "<<findKthPositive(data, k)<<endl;

    return 0;
}

// 1539. Kth Missing Positive Number
// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.

// Example 1:

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.