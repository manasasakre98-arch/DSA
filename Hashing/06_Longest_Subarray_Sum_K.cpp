/*
Problem:
Find the length of the longest subarray whose sum is equal to K.

Example:

Input:
5
1 -1 5 -2 3
K = 3

Output:
4

Algorithm:
1. Create an unordered_map to store:
   prefix sum -> earliest index
2. Store prefixIndex[0] = -1 as the base case.
3. Traverse the array and calculate the prefix sum.
4. Check whether (prefixSum - K) exists in the map.
5. If it exists, calculate the length of the subarray.
6. Update the maximum length.
7. Store the current prefix sum only if it has not appeared before.
8. Return the maximum length.

Time Complexity:
O(n) average

Space Complexity:
O(n)
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int longestSubarraySumK(vector<int>& nums, int k)
{
    unordered_map<int, int> firstIndex;

    firstIndex[0] = -1;

    int sum = 0;
    int maxLen = 0;

    for(int i=0;i<nums.size();i++)
    {
        sum += nums[i];

        int required = sum - k;

        if(firstIndex.find(required) != firstIndex.end())
        {
            int length = i - firstIndex[required];

            maxLen = max(maxLen, length);
        }

        if(firstIndex.find(sum) == firstIndex.end())
        {
            firstIndex[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    vector<int> nums(n);

    cout<< "Enter array elements: ";

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int k;
    cout<<"Enter K: ";
    cin>>k;
    int result = longestSubarraySumK(nums, k);
    cout<<"Longest subarray length = " << result << endl;

    return 0;
}