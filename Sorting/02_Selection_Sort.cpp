/*
Problem:
Selection Sort

Algorithm:
1. Read the size of the array.
2. Store all elements in the array.
3. Assume the current element is the smallest.
4. Compare it with all remaining elements.
5. Find the smallest element in the unsorted part.
6. Swap it with the current element.
7. Repeat until the array is sorted.
8. Print the sorted array.

Example:

Input:
5
64 25 12 22 11

Output:
11 12 22 25 64

Time Complexity:
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(1)
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
    cout<<"Sorted Array: ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}