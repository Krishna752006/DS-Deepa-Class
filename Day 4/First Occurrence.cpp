/*

Write a C++ Program to find the first occurrence of a target element in a sorted array with duplicates.

Sample Input1:
Enter the size of the array: 8                                                  
Enter the sorted array elements (space-separated): 1 2 2 2 3 4 4 5              
Enter the target value to search for: 2   
Sample Output1:
The first occurrence of 2 is at index 1. 
 
*/



#include <iostream>
using namespace std;

// Function to find the first occurrence of the target
int findFirstOccurrence(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1; // Initialize result to -1 (target not found)

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index
        if(arr[mid] == target)
        {
            result = mid;
            right = mid - 1;
        }
        else if(arr[mid] < target)
        {
            left = mid + 1;
        }
        else if(arr[mid]>target)
        {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    // Read the size of the array
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Read the array elements
    int arr[size];
    cout << "Enter the sorted array elements (space-separated): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Read the target value
    int target;
    cout << "Enter the target value to search for: ";
    cin >> target;

    // Find the first occurrence of the target
    int index = findFirstOccurrence(arr, size, target);

    // Output the result
    if (index != -1) {
        cout << "The first occurrence of " << target << " is at index " << index << "." << endl;
    } else {
        cout << target << " is not found in the array." << endl;
    }

    return 0;
}