/*
Problem: Maximum Sum Subarray of Size K (Fixed-size Sliding Window)

Algorithm:
1. Calculate sum of the first window(first k elements).
2. Slide the window one step at a time:
   - subtract the outgoing element (leavig from left)
   - add the incoming element (entering from right)
   - update maxSum if current window sum is bigger
3. Return maxSum

Time Complexity: O(n) - each element added once, removed once
Space Complexity: O(1) - just a few variables, no extra data structure
*/

#include <iostream>
using namespace std;

int maxSumSubarray(int arr[], int n, int k){
    int windowSum = 0;

    // Step 1: calculate sum of first window
    for(int i=0; i<k; i++){
        windowSum += arr[i];
    }
    int maxSum = windowSum;

    // Step 2: slide the window
    for(int i=k;i<n;i++){
        windowSum += arr[i] - arr[i-k]; // add incoming element, remove outgoing element
        maxSum = max(maxSum, windowSum); // update maxSum if current window sum is bigger
    }
    return maxSum;
}

int main(){
    int arr[] = { 2,1,5,1,3,2 };
    int n = 6, k = 3;
    cout << maxSumSubarray(arr,n, k);
    return 0;
}