/*
Problem:
Count the frequency of each element in an array.

Algorithm:
1. Read the array.
2. Create an unordered_map.
3. Traverse the array.
4. Increase the frequency of every element.
5. Print the frequencies.

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

    cout<<"Frequency of Elements: ";

    for(auto element:freq){
        cout<<element.first<<"->"<<element.second<<endl;
    }
    return 0;
}
