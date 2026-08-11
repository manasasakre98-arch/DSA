/*
Problem:
Sort an array in descending order.

Algorithm:
1. Read the array.
2. Compare adjacent elements.
3. If arr[j] < arr[j + 1], swap them.
4. Repeat for all passes.
5. Print the sorted array.

Time Complexity:
O(n^2)

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

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout<<"Descending Array: ";
    for(int i=0;i<n;i++)
    {
        cout<< arr[i] <<" ";
    }
    return 0;
}