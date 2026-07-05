/*
Problem:
Count the Number of Vowels in a String

Algorithm:
1. Read a string from the user.
2. Initialize a variable 'count' to 0.
3. Traverse each character of the string.
4. Check if the character is a vowel
   (a, e, i, o, u, A, E, I, O, U).
5. If it is a vowel, increment count.
6. Print the total number of vowels.

Example:

Input:
Education

Output:
Vowels = 5

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

    cout<<"Enter a string:";
    cin>>str;

    int count = 0;

    for(int i=0;i<str.length();i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            count++;
        }
    }

    cout<<"Number of Vowels = "<<count;

    return 0;
}