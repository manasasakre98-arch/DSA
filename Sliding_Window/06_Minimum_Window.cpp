/*
Problem: Minimum Window Substring

Algorithm:
1. need = frequency map of characters required (from t)
2. required = number of UNIQUE characters needed
3. Expand window with right:
   - add s[right] to windowCounts
   - if windowCounts[c] == need[c], increment formed (exact match, not >=)
4. While formed == required (window is valid):
   - record window size if smallest so far
   - shrink from left: remove s[left] from windowCounts
   - if removing drops windowCounts[c] below need[c], decrement formed
   - left++
5. Return smallest valid window found

Time Complexity: O(|s| + |t|) — each character in s visited by right once,
                  and by left at most once (left never resets backward)
Space Complexity: O(|s| + |t|) — for the two hashmaps
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // 1. What do we need?
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size();
        int formed = 0;

        // 2. What do we currently have?
        unordered_map<char, int> windowCounts;

        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        // 3. Expand window using right
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            windowCounts[c]++;

            // Did this character complete one requirement?
            if (need.count(c) && windowCounts[c] == need[c]) {
                formed++;
            }

            // 4. Window is valid -> try shrinking
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                windowCounts[leftChar]--;

                // Did removing it break a requirement?
                if (need.count(leftChar) && windowCounts[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        // 5. Did we find any valid window?
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";

    string result = sol.minWindow(s, t);
    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}