/*
Write a CPP program to delete minimum element from a given array.
*/
#include <iostream>
using namespace std;
int min(int a,int b)
{
    if (a>b)
    {
        return b;
    }
    else if (a<b)
    {
        return a; 
    }
    else
    {
        return a;
    }
}
void del(int a[],int b,int n)
{
    bool to = false;
    for(int i =0;i<n-1;i++)
    {
        if(a[i]==b)
        {
            to = true;
        }
        if(to)
        {
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1]=a[i];
        }
        cout << a[i] << " ";
    }
}
int main()
{
    int b;
    cout << "Enter Size of Array: ";
    cin >> b;
    int a[b];
    cout << "Enter the Elements: ";
    int c = 234567;
    for (int i = 0; i<b;i++)
    {
        cin >> a[i];
        c = min(c,a[i]);
    }
    cout << "Array after deletion: ";
    del(a,c,b);
    return 0;
}