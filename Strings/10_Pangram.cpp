/*
Time Complexity: O(n) — single pass through the string.

Space Complexity: O(1) — the set holds at most 26 characters, a fixed bound regardless of input size.
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> seen;

        for (char c : sentence) {
            if (isalpha(c)) {
                seen.insert(tolower(c));
            }
        }

        return seen.size() == 26;
    }
};

int main() {
    Solution sol;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";

    bool result = sol.checkIfPangram(sentence);
    cout << (result ? "true" : "false") << endl;

    return 0;
}