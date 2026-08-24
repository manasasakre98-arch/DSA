/*
Problem: Move Zeroes to end (in-place, two pointers)

Algorithm:
1. slow = -1 (tracks last position where a non-zero value was placed)
2. fast scans from 0 to n-1
3. If arr[fast] != 0: slow++, arr[slow] = arr[fast] (place non-zero value)
4. After loop, fill everything from slow+1 to end with 0

Time Complexity: O(n) - fast visits every element once
Space Complexity: O(1) - in-place
*/

#include<iostream>
using namespace std;

void moveZeroes(int arr[], int n){
    int slow = -1;

    for(int fast = 0; fast < n; fast ++){
        if(arr[fast] != 0){
            slow++;
            arr[slow] = arr[fast];
        }
    }

    for(int i=slow+1;i<n;i++){
        arr[i] = 0;
    }
}

int main(){
    int arr[] = {0, 1, 0, 3, 12};
    int n=5;
    moveZeroes(arr, n);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}