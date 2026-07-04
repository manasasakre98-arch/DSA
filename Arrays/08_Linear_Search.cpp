/*
Problem:
Linear Search

Algorithm:
1. Read the size of the array.
2. Store all elements in the array.
3. Read the element to be searched.
4. Traverse the array from the first element.
5. Compare each element with the search element.
6. If found, print the index.
7. Otherwise, print "Element Not Found".

Example:

Input:
5
10 20 30 40 50
30

Output:
Element Found at Index 2

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include<iostream>
using namespace std;

int main(){
    int n,key;

    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the element to search: ";
    cin>>key;

    int index = -1;

    for(int i = 0;i<n;i++){
        if(arr[i] == key)
        {
            index = i;
            break;
        }
    }

    if(index != -1)
      cout<<"Element Found at Index "<<index;
    else
      cout<<"Element Not Found";

    return 0;
}