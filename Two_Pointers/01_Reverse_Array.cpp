/*
Problem: Reverse an array in-place using two pointers

Algorithm:
1. left = 0, right = n-1
2. While left < right:
   - swap arr[left] and arr[right]
   - left++, right--
3. Stop when pointers meet or cross

Time Complexity: O(n) - each element visited once
Space Complexity: O(1) - in-place, no extra array
*/

#include<iostream>
using namespace std;

void reverseArray(int arr[], int n){
    int left=0, right=n-1;
    while (left < right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n=5;
    reverseArray(arr, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}