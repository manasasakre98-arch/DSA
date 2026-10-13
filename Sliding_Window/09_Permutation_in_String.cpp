/*
Time Complexity: O(26 · m), which is O(m): each of the m steps does an O(1) update and a 26-element comparison.

Space Complexity: O(1): two fixed arrays of 26 counters.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> need(26, 0), window(26, 0);
        for (char c : s1) need[c - 'a']++;

        for (int right = 0; right < m; right++) {
            window[s2[right] - 'a']++;

            // keep the window size fixed at n
            if (right >= n) {
                window[s2[right - n] - 'a']--;
            }

            if (window == need) return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "ab", s2 = "eidbaooo";

    bool result = sol.checkInclusion(s1, s2);
    cout << (result ? "true" : "false") << endl;   // true

    return 0;
}