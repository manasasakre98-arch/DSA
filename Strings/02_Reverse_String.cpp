/*
Problem:
Reverse a String

Algorithm:
1. Read a string from the user.
2. Start one loop from the last character.
3. Print each character until the first character.

Example:

Input:
Hello

Output:
olleH

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

    cout<<"Reversed String: ";
    for(int i=str.length()-1;i>=0;i--){
        cout<<str[i];
    }
    return 0;
}

//Using swap Reverse the string
/*
Problem:
Reverse a String

Algorithm:
1. Read a string from the user.
2. Initialize two pointers:
   - left = 0
   - right = last index of the string.
3. Swap the characters at left and right.
4. Increment left and decrement right.
5. Repeat until left is less than right.
6. Print the reversed string.

Example:

Input:
Hello

Output:
olleH

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    int left = 0;
    int right = str.length() - 1;

    while(left < right)
    {
        swap(str[left], str[right]);

        left++;
        right--;
    }

    cout << "Reversed String: " << str;

    return 0;
}