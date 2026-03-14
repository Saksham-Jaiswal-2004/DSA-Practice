#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxProduct(vector<int>& nums) 
{
    int n = nums.size();
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for(int i=1 ; i<n ; i++)
    {
        int tempMax = max({nums[i], maxProd*nums[i], minProd*nums[i]});
        int tempMin = min({nums[i], maxProd*nums[i], minProd*nums[i]});

        maxProd = tempMax;
        minProd = tempMin;

        result = max(result, maxProd);
    }

    return result;
}

int main()
{
    vector<int> data = {2, 3, -2, 4};
    int res = maxProduct(data);

    cout<<"Given Data:"<<endl;
    for(int i: data)
    cout<<i<<" ";

    cout<<"\n\nMaximum Product: "<<res<<endl;

    return 0;
}

// 152. Maximum Product Subarray
// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.