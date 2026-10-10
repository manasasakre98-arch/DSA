/*
Time Complexity: O(n): each pointer moves forward at most n times, and the work per step is O(1).

Space Complexity: O(1): a fixed array of 26 counters.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // replacements needed = window size - most frequent letter count
            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;

    int result = sol.characterReplacement(s, k);
    cout << "Longest Substring Length: " << result << endl;   // 4

    return 0;
}
