/*
Problem:
Count the number of subarrays whose sum is equal to K.

Example:

Input:
Array = [1, 1, 1]
K = 2

Output:
2

Explanation:
[1, 1] -> 2
[1, 1] -> 2

Algorithm:
1. Create an unordered_map to store:
   prefix sum -> frequency
2. Store prefixCount[0] = 1 to represent the empty prefix.
3. Initialize sum = 0 and count = 0.
4. Traverse the array.
5. Add the current element to sum.
6. Calculate required prefix sum:
      required = sum - K
7. Check whether required exists in the hash map.
8. If it exists, add its frequency to count.
9. Store the current prefix sum in the hash map.
10. Return count.

Time Complexity:
O(n) average

Space Complexity:
O(n)
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int> prefixCount;

    prefixCount[0] = 1;

    int sum = 0;
    int count = 0;

    for(int num : nums)
    {
        sum += num;

        int required = sum - k;

        if(prefixCount.find(required)!= prefixCount.end())
        {
            count += prefixCount[required];
        }
        prefixCount[sum]++;
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter array elements: ";
    for(int i =0;i<n;i++)
    {
        cin>>nums[i];
    }
    int k;
    cout<<"Enter K:";
    cin>>k;
    int result = subarraySum(nums,k);
    cout<<"Number of subarray with sum"<<k<<"="<<result<<endl;
    return 0;
}