/*
Time Complexity: O(n) — one pass through the array.

Space Complexity: O(1) — two tracking variables only.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int secondLargest(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN;

        for (int num : nums) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second && num != first) {
                second = num;
            }
        }

        return second;   // INT_MIN if no valid second largest exists
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12, 35, 1, 10, 34, 1};

    int result = sol.secondLargest(nums);
    cout << "Second Largest: " << result << endl;

    return 0;
}