/*
Problem:
Sum of Elements in an Array

Algorithm:
1. Read the size of the array.
2. Store all elements.
3. Initialize sum = 0.
4. Traverse the array.
5. Add each element to sum.
6. Print the total sum.

Example:

Input:
5
10 20 30 40 50

Output:
Sum = 150

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include<iostream>
using namespace std;

int main(){
    int n,sum=0;
    cout<<"Enter the size of the array:";
    cin>>n;

    int arr[n];

    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    cout<<"Sum = " << sum;
    return 0;
}