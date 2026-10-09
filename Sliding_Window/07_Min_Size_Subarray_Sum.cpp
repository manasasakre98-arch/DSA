/*
Time Complexity: O(n): right and left each move forward at most n times.

Space Complexity: O(1): only a few variables.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, windowSum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];

            // window is valid: shrink it as much as possible
            while (windowSum >= target) {
                minLen = min(minLen, right - left + 1);
                windowSum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = sol.minSubArrayLen(target, nums);
    cout << "Minimal Length: " << result << endl;   // 2

    return 0;
}

