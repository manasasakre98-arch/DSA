/*
Problem:
Find Maximum and Minimum Element in an Array

Algorithm:
1. Read the size of the array.
2. Store all elements.
3. Assume the first element is both maximum and minimum.
4. Traverse the remaining elements.
5. Update maximum if a larger element is found.
6. Update minimum if a smaller element is found.
7. Print both maximum and minimum elements.

Example:

Input:
5
10 45 23 67 12

Output:
Maximum Element = 67
Minimum Element = 10

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maximum = arr[0];
    int minimum = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i] > maximum){
            maximum = arr[i];
        }
        if(arr[i] < minimum){
            minimum = arr[i];
        }
    }
    cout<<"Maximum Element: " << maximum << endl;
    cout<<"Minimum Element: " << minimum;

    return 0;
}