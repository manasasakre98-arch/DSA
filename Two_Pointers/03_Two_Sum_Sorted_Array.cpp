/*
Problem: Two Sum in Sorted Array using two pointers

Algorithm:
1. left = 0, right = n-1
2. While left < right:
   - if arr[left] + arr[right] == target, found the pair, stop
   - if sum < target, move left forward (increase sum)
   - if sum > target, move right backward (decrease sum)

Time Complexity: O(n) - each pointer moves at most n times total
Space Complexity: O(1) - no extra data structure
*/


#include<iostream>
using namespace std;

void twoSum(int arr[], int n, int target){
    int left = 0, right = n-1;

    while (left < right){
        int sum = arr[left] + arr[right];

        if (sum == target){
            cout << "Found pair: index " << left << " and index" << right;
            return;
        }
        else if (sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    cout << "No pair found";
}

int main(){
    int arr[] = {2, 7, 11, 15};
    int n = 4;
    twoSum(arr, n, 9);
    return 0;
}