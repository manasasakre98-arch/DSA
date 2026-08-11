/*
Problem:
Bubble Sort

Algorithm:
1. Read the size of the array.
2. Store all elements in the array.
3. Compare adjacent elements.
4. If the left element is greater than the right element, swap them.
5. Repeat the process for all elements.
6. After each pass, the largest element moves to its correct position.
7. Print the sorted array.

Example:

Input:
5
64 34 25 12 22

Output:
12 22 25 34 64

Time Complexity:
Best Case: O(n) (Optimized Bubble Sort)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}