/*
Problem: Power of a Number (x^n) using recursion

Algorithm:
1. Base case: if n == 0, return 1 (x^0 = 1 for any x)
2. Recursive case: return x * power(x, n-1) -> x stays FIXED, only shrinks toward 0

Time Complexity: O(n) - one call per decrement of n
Space Complexity: O(n) - call stack holds n frames at deepest point
*/

#include<iostream>
using namespace std;

int power(int x,int n){
    if(n==0) return 1;
    return x*power(x,n-1);
}
int main(){
    cout<<power(2,3);
    return 0;
}