/*
Problem:
Check whether an array is sorted in ascending order.

Algorithm:
1. Read the array.
2. Start from the first element.
3. Compare each element with the next element.
4. If arr[i] > arr[i + 1], the array is not sorted.
5. If no such pair is found, the array is sorted.

Example:

Input:
5
1 2 3 4 5

Output:
Array is sorted.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    bool sorted = true;

    for(int i=0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            sorted = false;
            break;
        }
    }

    if(sorted)
    {
        cout<<"Array is sorted.";
    }
    else{
        cout<<"Array is not sorted.";
    }
    return 0;
}