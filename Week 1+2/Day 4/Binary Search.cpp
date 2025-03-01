#include <iostream>
using namespace std;
int binary(int l,int r,int Arr[],int t)
{
    while(l<=r)
    {
        int m = l + (r-l)/2;
        if(Arr[m] == t)
        {
            return m;
        }
        else if(Arr[m] > t)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}
int main()
{
    int Arr[] = {1,3,5,6,7,8,69};
    int l = 0,r = (sizeof(Arr)/sizeof(Arr[0])) - 1;
    int t = 10;
    cout << "Target Index: " << binary(l,r,Arr,t);
    return 0;
}
