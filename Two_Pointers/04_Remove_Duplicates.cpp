/*
Problem: Remove Duplicates from Sorted Array (in-place, two pointers)

Algorithm:
1. slow = 0 (points to last unique element placed)
2. fast = 1 (scans through array looking for new unique values)
3. While fast < n:
   - if arr[fast] != arr[slow]: found a new unique value
    -> slow++, then arr[slow] = arr[fast]
   - fast++ (always moves, every iteration)
4. Returns slow + 1 (count of unique elements)

Time Complexity: O(n) - faast visits every element once
Space Complexity: O(1) - in-place, no extra array
*/

#include<iostream>
using namespace std;

int removeDuplicates(int arr[], int n){
    if(n==0) return 0;

    int slow = 0;

    for(int fast = 1;fast<n;fast++){
        if(arr[fast] != arr[slow]){
            slow++;
            arr[slow] = arr[fast];
        }
    }
    return slow+1;
}

int main(){
    int arr[] = {1, 1, 2, 2, 3};
    int n = 5;
    int uniqueCount = removeDuplicates(arr, n);

    cout << "Unique count: " << uniqueCount << endl;
    cout << "Array: ";
    for(int i=0; i < uniqueCount; i++) cout<<arr[i]<<" ";
    return 0;
}