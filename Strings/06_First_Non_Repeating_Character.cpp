/*
Problem:
Find the First Non-Repeating Character in a String

Algorithm:
1. Read a string from the user.
2. Create a frequency array of size 256 and initialize it to 0.
3. Traverse the string and count the frequency of each character.
4. Traverse the string again.
5. If the frequency of a character is 1, print it and stop.
6. If no such character exists, print a message.

Example:

Input:
aabbcdde

Output:
First Non-Repeating Character = c

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

    int freq[256] = {0};

    for(int i=0;i<str.length();i++){
        freq[str[i]]++;
    }

    bool found = false;

    for(int i = 0;i<str.length();i++){
        if(freq[str[i]] == 1){
            cout<<"First Non-Repeating Character = "<< str[i];
            found = true;
            break;
        }
    }

    if(!found){
        cout<<"No Non-Repeating Character Found";
    }
    return 0;
}