/*
Problem:
Find the first repeating element in an array.

Algorithm:
1. Read the array.
2. Count frequencies using unordered_map.
3. Traverse the array again.
4. Print the first element with frequency greater than 1.

Example:

Input:
6
1 5 3 4 3 5

Output:
5

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;

    // Count frequency
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Find first repeating element
    for(int i = 0; i < n; i++)
    {
        if(freq[arr[i]] > 1)
        {
            cout << "First Repeating Element: " << arr[i];
            return 0;
        }
    }

    cout << "No Repeating Element Found.";

    return 0;
}

//Alternative method 

// unordered_set<int> seen;

// for(int i=0;i<n;i++){
//     if(seen.find(arr[i])!=seen.end())
//     {
//         cout<<"First Duplicate Encountered: " << arr[i];
//         return 0;
//     }

//     seen.insert(arr[i]);
// }