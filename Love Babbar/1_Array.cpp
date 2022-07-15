// Problem 1: Reverse an array or string

#include <iostream>
using namespace std;

/*
 * Iterative way:
 * Time Complexity: O(N)
 */

// Reverse array from start to end
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/*
 * Recursive ways:
 * Time Complexity: O(N)
 */

void recRevArray(int arr[], int start, int end)
{
    if (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Recursive Function  Call
        recRevArray(arr, start + 1, end - 1);
    }
}

// Print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver function
int main()
{
    int n = 0;
    cout << "Enter size of an array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of an array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Calling reverseArray Function: To reverse an array
    // reverseArray(arr, 0, n-1);
    recRevArray(arr, 0, n - 1);

    // Calling printArray: To print reversed array
    printArray(arr, n);
    return 0;
}
