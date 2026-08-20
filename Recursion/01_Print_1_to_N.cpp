/*
Problem: Print 1 to N using recursion

Algorithm:
1. Base case: if n == 0, stop (nothing to print)
2. Recursive case: first call print(n-1) to handle smaller numbers,
   THEN print n — this ensures smaller numbers print first
3. Recursion goes down to 1, then prints happen on the way back up

Time Complexity: O(n) — one call per number from n down to 0
Space Complexity: O(n) — call stack holds n frames at the deepest point
*/

#include <iostream>
using namespace std;

void print1ToN(int n) {
    if (n == 0) return;        // base case: stop when n reaches 0
    print1ToN(n - 1);          // recursive call FIRST (go down to smaller n)
    cout << n << " ";          // print AFTER the recursive call (on the way back up)
}

int main() {
    print1ToN(4);
    return 0;
}