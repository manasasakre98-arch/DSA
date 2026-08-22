/*
Problem: Check if a string is a palindrome using two pointers

Algorithm:
1. left=0, right=length-1
2. While left < right:
   - if str[left] != str[right], return false immediately
   - else move both pointers inward
3. If loop completes without mismatch, return true

Time Complexity: O(n) - each character checked once
Space Complexity: O(1) - no extra string/array created
*/

#include<iostream>
using namespace std;

bool isPalindrome(string str){
    int left=0, right= str.length() - 1;
    while(left < right){
        if(str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}
int main(){
    cout << (isPalindrome("madam")?"true":"false")<<endl;
    cout << (isPalindrome("hello")?"true":"false")<<endl;
    return 0;
}