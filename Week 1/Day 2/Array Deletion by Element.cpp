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
    cout << "\nEnter Element to Delete: ";
    int b;
    bool index;
    cin >> b;
    for(int i =0;i<a;i++)
    {
        if( Arr[i] == b)
        {
            index = true;
        }
        if(index)
        {
            Arr[i] = Arr[i+1];
        }
    }
    cout << "After Deletion: ";
    for (int i = 0; i<a-1;i++)
    {
        cout << Arr[i] << " ";
    }
    return 0;
}