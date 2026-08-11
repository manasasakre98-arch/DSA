/*
Problem:
Remove duplicate elements from an array.

Algorithm:
1. Read the array.
2. Create an unordered_set.
3. Traverse the array.
4. If element is not present, print it and insert it.

Example:

Input:
6
1 2 2 3 3 4

Output:
1 2 3 4

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include<iostream>
#include<unordered_set>
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

    unordered_set <int> seen;

    cout<<"Array after removing duplicates: ";

    for(int i=0;i<n;i++){
        if(seen.find(arr[i]) == seen.end()){
            cout<<arr[i]<<" ";
            seen.insert(arr[i]);
        }
    }
    return 0;
}

//Alternative 1 using set
// set<int> uniqueElement; //gets sorted

//Alternative 2 using vector (helps return the result rather than print it)
// vector<int> result;

// if(seen.find(arr[i]) == seen.end())
// {
//     result.push_back(arr[i]);
//     seen.insert(arr[i]);
// }