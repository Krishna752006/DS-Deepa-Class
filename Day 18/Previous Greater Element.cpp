#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int arr[] = {4, 5, 25, 0, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int arr2[len];
    stack<pair<int, int>> s;
    pair<int, int> p;
    fill(arr2, arr2 + len, -1);
    for (int i = 0; i < len; i++) {
        while (!s.empty() && s.top().first <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            arr2[i] = s.top().first;
        }
        s.push({arr[i], i});
    }
    for(int i = 0;i<len;i++)
    {
        if (arr2[i] == -1)
        arr2[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        cout << arr2[i] << " ";
    }
}
