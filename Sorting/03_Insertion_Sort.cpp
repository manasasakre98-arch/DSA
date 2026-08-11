/*
Problem:
Insertion Sort

Algorithm:
1. Start from the second element.
2. Store the current element in key.
3. Compare key with elements before it.
4. Shift larger elements one position to the right.
5. Insert key into its correct position.
6. Repeat until the array is sorted.

Example:

Input:
5
5 3 4 1 2

Output:
1 2 3 4 5

Time Complexity:
Best Case: O(n)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(1)
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >=0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout<<"Sorted Array: ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}