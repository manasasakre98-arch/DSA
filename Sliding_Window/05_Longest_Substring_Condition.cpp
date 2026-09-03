/*
Problem: Longest Subarray with Sum <= K (Variable-size window, positive integers only)

Algorithm:
1.right expands the window, adding arr[right] to windowSum
2. While windowSum > K: shrink from left, subtracting arr[left], left++
3. After ensuring validity, update maxLen = max(maxLen, right - left + 1)

Time Complexity: O(n) - each element added once (by right), removed at most once (by left)
Space Complexity: O(1) - just a running sum, no extra structure
*/

#include<iostream>
using namespace std;

int longestSubarraySumK(int arr[], int n, int k) {
    int left = 0, windowSum = 0, maxLen = 0;

    for (int right = 0;right < n;right++){
        windowSum += arr[right];

        while (windowSum > k) {
            windowSum -= arr[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main(){
    int arr[] = {2, 1, 1, 3, 4, 5};
    int n = 6, k = 5;
    cout << longestSubarraySumK(arr, n, k);
    return 0;
}