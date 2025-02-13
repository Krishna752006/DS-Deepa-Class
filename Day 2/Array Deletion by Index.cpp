#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the size of Array: ";
    int a;
    cin >> a;
    int Arr[a];
    cout << "Enter Elements: ";
    for (int i = 0; i<a;i++)
    {
        cin >> Arr[i];
    }
    cout << "Original: ";
    for (int i = 0; i<a;i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\nEnter Index to Delete: ";
    int b;
    cin >> b;
    if(b>a || b<0)
    {
        cout << "Invalid Position";
    }
    else
    {
        for(int i = b;i<a-1;i++)
        {
            Arr[i] = Arr[i+1];
        }
        cout << "After Deletion: ";
        for (int i = 0; i<a-1;i++)
         {
        cout << Arr[i] << " ";
        }
    }
    return 0;
}