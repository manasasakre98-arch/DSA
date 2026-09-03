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
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    
    unordered_map<char, int> need;
    for (char c : t) need[c]++;
    
    int required = need.size();     // unique characters needed
    int formed = 0;                  // unique characters currently satisfied
    unordered_map<char, int> windowCounts;
    
    int left = 0;
    int minLen = INT_MAX, minStart = 0;
    
    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        windowCounts[c]++;
        
        // check if this character's requirement is now exactly met
        if (need.count(c) && windowCounts[c] == need[c]) {
            formed++;
        }
        
        // window is valid, try shrinking
        while (formed == required) {
            // record if this is the smallest window so far
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            
            // remove leftmost character
            char leftChar = s[left];
            windowCounts[leftChar]--;
            
            // if this drops below required count, window becomes invalid
            if (need.count(leftChar) && windowCounts[leftChar] < need[leftChar]) {
                formed--;
            }
            
            left++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC");
    return 0;
}