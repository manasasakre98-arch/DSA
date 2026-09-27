/*
Q2) Rotate an Array by K Steps
Example: Input: nums = [1,2,3,4,5,6,7],
   k = 3,Output: [5,6,7,1,2,3,4]

   "Right rotate -> take the last k elements -> bring them to the front -> use 3 reversals."

Time Complexity: O(n) -- array elements are processed a constant number of times.
Space Complexity: O(1) -- auxiliary space.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
   void rotate(vector<int>& nums, int k){
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
   }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    sol.rotate(nums, k);
    cout << "Rotated Array: ";
    for(int num:nums) cout << num << "";
    cout << endl;
    return 0;
}