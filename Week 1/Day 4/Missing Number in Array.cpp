/*
Write a C++ program to find the missing number in a given array
sample input-output1:
Enter the value of N: 6
Enter 5 sorted elements: 1 2 4 5 6
Missing number: 3



*/
#include <iostream>
using namespace std;
int main()
{
    int b;
    cout << "Enter the value of N: ";
    cin >> b;
    int a[b];
    cout << "Enter " << b << " sorted elements: ";
    for(int i =0;i<b;i++)
    {
        cin >> a[i];
    }
    int l = 0;
    int r = b-1;
    int m;
    int miss;
    while(l != r)
    {
        m = l + (r-l)/2;
        if(a[m] == m)
        {
            l = m + 1;
        }
        else if(a[m] != m)
        {
            r = m - 1;
        }
        if ( l == r)
        {
            miss = l;   
        }
    }
    cout << "Missing number: " << miss;
    return 0;
}