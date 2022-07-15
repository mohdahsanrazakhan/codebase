// Problem 2: Maximum and minimum of an array using minimum number of comparisions

#include <iostream>
using namespace std;

/*
 * Iterative way:
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */ 

// Finding Maximum Value
int maxVal(int arr[], int size)
{
    int maxi = INT32_MIN;
    
    for(int i = 0; i < size; i++) {
        if(arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}

// Finding Minimum Value
int minVal(int arr[], int size)
{
    int mini = INT32_MAX;
    for(int i = 0; i < size; i++) {
        if(mini > arr[i])
            mini = arr[i];
    }
    return mini;
    
}

// Driver function
int main()
{
    int n = 0;
    cout << "Enter size of an array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of an array: " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxVal(arr, n) << endl;
    
    cout << minVal(arr, n) << endl;
    return 0;
}
