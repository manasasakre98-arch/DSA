/*
Problem:
Array Traversal

Algorithm:
1. Read the size of the array.
2. Store all elements.
3. Traverse the array from first to last element.
4. Print each element.

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

    cout << "Traversing the array:" << endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}