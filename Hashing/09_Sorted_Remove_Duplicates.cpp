/*
Time Complexity: O(n) — fast visits every element once.

Space Complexity: O(1) — in-place modification, no extra array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int slow = 0;

        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;   // count of unique elements
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3};

    int newLength = sol.removeDuplicates(nums);

    cout << "New Length: " << newLength << endl;
    cout << "Array: ";
    for (int i = 0; i < newLength; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}

