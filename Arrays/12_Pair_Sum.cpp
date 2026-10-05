/*
Time Complexity: O(n) — single pass, each hashmap operation is O(1) average.

Space Complexity: O(n) — hashmap stores up to n elements.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;   // value -> index

        for (int i = 0; i < (int)nums.size(); i++) {  // i < (int)nums.size() -- to avoid signed/unsigned comparison warning
            int complement = target - nums[i];
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }

        return {};   // no valid pair found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty())
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    else
        cout << "No valid pair found" << endl;

    return 0;
}