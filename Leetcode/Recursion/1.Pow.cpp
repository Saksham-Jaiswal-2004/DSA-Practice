#include<iostream>

using namespace std;

double myPow(double x, int n)
{
    long long N = n;

    if(N == 1)
    return x;

    if(N == 0)
    return 1;

    int sign = 1;

    if(N < 0)
    {
        sign = -1;
        N *= -1;
    }

    double ans;

    if(N%2 == 0)
    ans = myPow(x*x, N/2);
    else
    ans = x * myPow(x*x, (N-1)/2);

    if(sign == 1)
    return ans;
    else 
    return 1/ans;
}

int main()
{
    double x = 2.0;
    int n = 6;

    cout<<"Number: "<<x<<endl;
    cout<<"Power: "<<n<<endl;
    cout<<"Result: "<<myPow(x, n)<<endl;

    return 0;
}

// 50. Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn). 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25