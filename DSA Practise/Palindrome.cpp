#include<iostream>
#include<cmath>

using namespace std;

bool isPalindrome(int x) 
{
    string num = to_string(x);
    int s = 0;
    int e = num.size()-1;

    if(num[0] == '-')
    return false;

    while(s<e)
    {
        if(num[s] != num[e])
        return false;

        s++;
        e--;
    }

    return true;
}

int main()
{
    int data = 121;

    if (isPalindrome(data))
    cout<<"Palindrome!"<<endl;
    else
    cout<<"Not Palindrome!"<<endl;

    return 0;
}