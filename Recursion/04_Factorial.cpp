/*
Problem: Factorial of N using recursion

Algorithm:
1. Base case: if n == 0, return 1 (0! = 1 by definition)
2. Recursive case: return n * factorial_of_N(n-1)

Time Complexity: O(n) — one call per number from n down to 0
Space Complexity: O(n) — call stack holds n frames at deepest point
*/

#include <iostream>
using namespace std;

int factorial_of_N(int n) {
    if (n == 0) return 1;              // base case: 0! = 1
    return n * factorial_of_N(n - 1);  // n times factorial of (n-1)
}

int main() {
    cout << factorial_of_N(4);         // must print the result to see it
    return 0;
}

