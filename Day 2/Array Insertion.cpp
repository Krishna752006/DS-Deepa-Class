/*Write a C++ program using a class to insert an element into  an array. 
The class should:
Accept an array of n elements from the user.
Display the array before and after insertion.
 insert a new element at a specified position.
Ensure that the insertion position is valid else display "Invalid position"
Use a constructor to initialize the array elements.
sample input-output1:
Size of array: 4
Enter elements: 5 6 44 33
Original: 5 6 44 33
Insert element  : 2
Enter Index (0-based index): 6
Invalid position
After insertion: 5 6 44 33
sample input-output2:
Size of array: 5
Enter elements: 3 4 3 2 3
Original: 3 4 3 2 3
Insert element  : 5
Enter Index (0-based index): 2
After insertion: 3 4 5 3 2 3

*/
#include <iostream>
using namespace std;
int main()
{
    cout << "Size of array: ";
    int a;
    cin >> a;
    int Arr [a];
    cout << "Enter elements: ";
    for(int i = 0;i<a;i++)
    {
        cin >> Arr[i];
    }
    cout << "Original: ";
    for(int i = 0;i<a;i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\nInsert element : ";
    int b;
    cin >> b;
    cout << "Enter Index (0-based index): ";
    int c;
    cin >> c;
    if (c>a || c<0)
    {
        cout << "Invalid Position";
        cout << "\nAfter Insertion: ";
        for(int i = 0;i<a;i++)
    {
        cout << Arr[i] << " ";
    }
    }
    else
    {
        int d = Arr[a-1];
    for (int i =a-1;i>c;i--)
    {
        Arr[i] = Arr[i-1];
    }
    Arr[c] = b;
    cout << "After Insertion: ";
    for(int i = 0;i<a;i++)
    {
        cout << Arr[i] << " ";
    }
    cout << d;
    }
    return 0;
}