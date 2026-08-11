/*
Problem:
Find the first non-repeating element in an array.

Algorithm:
1. Read the array.
2. Count the frequency of each element.
3. Traverse the array again.
4. Print the first element whose frequency is 1.

Example:

Input:
6
2 3 4 2 3 5

Output:
4

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    unordered_map <int, int> freq;

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=0;i<n;i++){
        if(freq[arr[i]] == 1){
            cout<<"First Non-Repeating Element: "<< arr[i];
            return 0;
        }
    }

    cout<<"No Non-Repeating Element Found.";
    return 0;
}