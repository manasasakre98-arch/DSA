/*
Problem: Sum of Digits using recursion

Algorithm:
1. Base case: if n == 0, return 0 (no digits left to add)
2. Recursive case: return (last digit) + sumOfDigits(remaining number)
   -> last digit = n % 10
   -> remaining number = n / 10

Time Complexity: O(d) where d = number of digits in n
Space Complexity: O(d) — call stack holds one frame per digit
*/

#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0;                      // base case
    return (n % 10) + sumOfDigits(n / 10);      // last digit + rest
}

int main() {
    cout << sumOfDigits(1234);
    return 0;
}