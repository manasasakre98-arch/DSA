/*
Problem:
Array Input and Output

Algorithm:
1. Read the size of the array.
2. Input all elements into the array.
3. Print all the elements.

Example:

Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Time Complexity:
O(n)

Space Complexity:
O(n)
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

    cout << "Array elements are: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}