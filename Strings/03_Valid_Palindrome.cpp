/*
Problem:
Check whether a String is a Palindrome

Algorithm:
1. Read a string from the user.
2. Initialize two pointers:
   - left = 0
   - right = last index of the string.
3. Compare characters at left and right.
4. If they are different, the string is not a palindrome.
5. Otherwise, move both pointers toward the center.
6. Repeat until left is greater than or equal to right.
7. If all characters match, the string is a palindrome.

Example:

Input:
madam

Output:
Palindrome

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;

    cout<<"Enter a string: ";
    cin>>str;

    int left = 0;
    int right = str.length() - 1;

    bool palindrome = true;

    while(left < right){
        if(str[left] != str[right]){
            palindrome = false;
            break;
        }
        left++;
        right--;
    }

    if(palindrome)
         cout<< "Palidrome";
    else
         cout<< "Not a Palindrome";

    return 0;
}