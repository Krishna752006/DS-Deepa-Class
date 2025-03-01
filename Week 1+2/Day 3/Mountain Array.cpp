/*Write a C++ program using a class to check whether an array is valid mountain array or not 
hint:An array is considered a mountain array if:
It has at least 3 elements.
There exists an index i such that:
arr[0] < arr[1] < ... < arr[i] (strictly increasing sequence)
arr[i] > arr[i+1] > ... > arr[n-1] (strictly decreasing sequence)
The peak element must not be the first or last element.
sample input-output1:
Enter size: 5                                                                   
Enter elements: 3 4 5 6 7                                                       
The array is NOT a valid mountain array. 
sample input-output2:
Enter size: 5                                                                   
Enter elements: 1 3 4 5 2                                                       
The array is a valid mountain array.

*/
#include <iostream>
using namespace std;
int main()
{
    int b,c = 0;
    cout << "Enter size: ";
    cin >> b;
    int a[b];
    cout << "Enter elements: ";
    for (int i = 0;i<b;i++)
    {
        cin >> a[i];
    }
    bool m = 1;
    for (int i = 1;i<b-1;i++)
    {
        if(c==0)
        {
            if(a[i-1]<a[i] && a[i]<a[i+1])
            {
                if(i == b-2)
                {
                    m = 0;
                    break;
                }
            }
            else
            {
                c = 1;
            }
        }
        else if(c == 1)
        {
            if(a[i]>a[i+1] && a[i-1]>a[i])
            {
                continue;
            }
            else
            {
                m = 0;
            }
        }
    }
    if (m == 1)
    {
        cout << "The array is a valid mountain array.";
    }
    else
    {
        cout << "The array is NOT a valid mountain array.";
    }
    return 0;
}