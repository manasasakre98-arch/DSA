/*
Problem: Sum of first N numbers using recursion

Algorithm:
1. Base case: if n == 0, return 0 (sum of nothing is 0)
2. Recursive case: return n + sum_of_first_N(n-1)
   -> add current n to the sum of everything smaller than n

Time Complexity: O(n) — one call for each number from n down to 0
Space Complexity: O(n) — call stack holds n frames at the deepest point
*/

#include <iostream>
using namespace std;

int sum_of_first_N(int n) {
    if (n == 0) return 0;              // base case: sum of 0 numbers is 0
    return n + sum_of_first_N(n - 1);  // add n to sum of (n-1) smaller numbers
}

int main() {
    cout << sum_of_first_N(4);
    return 0;
}

