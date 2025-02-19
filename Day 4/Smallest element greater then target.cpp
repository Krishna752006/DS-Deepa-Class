/*


Write a C++ Program to find the smallest element greater than a target element in a sorted array.

Sample Input-Output:
Enter the size of the sorted array: 5                                           
Enter 5 sorted elements: 1 2 3 5 6                                              
Enter the target element: 3                                                     
Smallest element greater than 3 is: 5                                           
                                                                                
                                       

*/

#include <iostream>
using namespace std;

int findSmallestGreater(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
        {
            result = arr[mid+1];
            left = mid + 1;
        }
        else if(arr[mid] > target)
        {
            right = mid -1;
        }
        else 
        {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, target;
    
    // Read the size of the array
    cout << "Enter the size of the sorted array: ";
    cin >> n;

    int arr[n];

    // Read the sorted array elements
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Read the target element
    cout << "Enter the target element: ";
    cin >> target;

    // Find the smallest element greater than the target
    int result = findSmallestGreater(arr, n, target);

    if (result != -1) {
        cout << "Smallest element greater than " << target << " is: " << result << endl;
    } else {
        cout << "No element found greater than " << target << endl;
    }

    return 0;
}
