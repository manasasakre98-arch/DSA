/*
Problem:
Find the Average of Elements in an Array

Algorithm:
1. Read the size of the array.
2. Store all elements in the array.
3. Initialize sum = 0.
4. Traverse the array and calculate the sum.
5. Divide the sum by the number of elements.
6. Print the average.

Example:

Input:
5
10 20 30 40 50

Output:
Average = 30

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    float sum = 0,average;
    
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    average = sum/n;

    cout<<"Average: " << average;
    return 0;
}