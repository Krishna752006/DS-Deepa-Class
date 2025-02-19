#include <iostream>
using namespace std;
int binary(int l,int r,int Arr[],int t)
{
    int result = -1;
    while(l<=r)
    {
        int m = l + (r-l)/2;
        if (Arr[m] == t)
        {
            r = m;
            l = m + 1;
        }
        else if(Arr[m] > t)
        {
            r = m - 1;
        }
        else if(Arr[m] < t)
        {
            l = m + 1;
        }
    }
    if (result = -1)
    {
        return r;
    }
    else
    {
        return result;
    }
}
int main()
{
    int Arr[] = {1,3,5,6,7,8,69};
    int l = 0,r = (sizeof(Arr)/sizeof(Arr[0])) - 1;
    int t = 10;
    cout << "Target Index: " << binary(l,r,Arr,t);
    return 0;
}
