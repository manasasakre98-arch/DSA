/*
Problem:
Count the Number of Consonants in a String

Algorithm:
1. Read a string from the user.
2. Initialize a variable 'count' to 0.
3. Traverse each character of the string.
4. Check whether the character is an alphabet.
5. If it is an alphabet and not a vowel, increment count.
6. Print the total number of consonants.

Example:

Input:
Education

Output:
Consonants = 4

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
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U'){
                count++;
            } 
        }
    }

    cout<<"Number of Consonants = " << count;

    return 0;
}