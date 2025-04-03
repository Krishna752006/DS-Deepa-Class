#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<pair<int,int>> s;
    int arr[] = {4,5,25,0,3};
    pair<int,int> p;
    int len = sizeof(arr)/sizeof(arr[0]);
    int arr2[len];
    fill(arr2, arr2+len, -1);
    for(int i = 0; i < len; i++)
    {
        while(!s.empty() && s.top().first < arr[i])
        {
            p = s.top();
            arr2[p.second] = arr[i];
            s.pop();
        }
        s.push({arr[i],i});
    }
    while(!s.empty())
    {
        p = s.top();
        arr2[p.second] = 0;
        s.pop();
    }
    for(int i = 0; i<=len-1;i++)
    {
        cout << arr2[i] << " ";
    }
}