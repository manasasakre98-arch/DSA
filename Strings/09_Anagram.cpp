/*
Time Complexity: O(n log n) — dominated by the two sorts.

Space Complexity: O(1) extra (ignoring sort's internal space) if in-place sort is used, or O(n) if the language copies strings first.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    bool result = sol.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl;

    return 0;
}