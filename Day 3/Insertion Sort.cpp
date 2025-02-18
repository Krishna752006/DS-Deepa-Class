/*
Write a C++ program for implementation of Insertion Sort

*/

#include <iostream>
using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    int temp;
  for(int i =1;i<n;i++)
  {
      for(int j = i; j>0;j--)
      {
          if(arr[j]<arr[j-1])
          {
              temp = arr[j];
              arr[j] = arr[j-1];
              arr[j-1] = temp;
          }
      }
  }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}