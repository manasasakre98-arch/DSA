/*
Problem:
Largest Element in an Array

Algorithm:
1. Read the size of the array.
2. Store all elements.
3. Assume the first element is the largest.
4. Traverse the remaining elements.
5. If the current element is greater than the largest, update the largest.
6. Print the largest element.

Example:

Input:
5
10 45 23 67 12

Output:
Largest Element = 67

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int largest = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>largest)
        {
            largest = arr[i];
        }
    }

    cout<<"Largest Element = "<<largest;
    return 0;
}