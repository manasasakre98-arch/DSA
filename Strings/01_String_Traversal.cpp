/*
Problem:
String Traversal

Algorithm:
1. Read a string from the user.
2. Traverse the string using a for loop.
3. Print each character one by one.

Example:

Input:
Hello

Output:
H
e
l
l
o

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

    cout<<"Characters in the string are:"<<endl;

    for(int i=0;i<str.length();i++)
    {
        cout<<str[i]<<endl;
    }

    return 0;
}


// Print Index and character together
#include<iostream>
#include<string>
using namespace std;
int main(){
   
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    cout<<"Characters in the string are:"<<endl;

    for(int i=0;i<str.length();i++)
    {
        cout<< "Index " << i << ":" << str[i]<<endl;
    }

    return 0;
}

