/*
Q1) Find the Largest Sum Contiguous SubArray(Kadane's Algorithm)
Example: Input: {-2, 1, -3, 4, -1, 2, 1, -5, 4}
        Output: 6 {Subarray: [4, -1, 2, 1]}

        " If the previous sum helps me, continue.
          If it hurts me,restart. Always remember the best."
                           OR
        " If the past helps you -> carry it forward.
          If the past only pulls you down -> let it go and start fresh.
          At every point -> keep track of the best you've achieved."

Time Complexity: O(n) -- We meet every element exactly once.
Space Complexity: O(1) -- Only two variables [currentSum, maxSum]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
   int maxSubArray(vector<int>& nums){
    int maxSum = nums[0];
    int currentSum = nums[0];

    for(int i=1; i<nums.size(); i++){
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
   }
};


int main(){
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = sol.maxSubArray(nums);
    cout << "Maximum SubArray Sum: " << result << endl;
    return 0;
}