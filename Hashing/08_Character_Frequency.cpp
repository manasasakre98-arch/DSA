/*
Time Complexity: O(n) — single pass, O(1) average per hashmap operation.

Space Complexity: O(k) — k unique characters stored (bounded by alphabet size, e.g., 26 or 256).
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> charFrequency(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        return freq;
    }
};

int main() {
    Solution sol;
    string s = "programming";

    unordered_map<char, int> result = sol.charFrequency(s);

    for (const auto& pair : result) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}