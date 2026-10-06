/*
Time Complexity: O(n) — each character is read once and reversed once across all words.

Space Complexity: O(n) — for the result string and stream buffering.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseEachWord(string s) {
        istringstream iss(s);
        string word, result;

        while (iss >> word) {
            reverse(word.begin(), word.end());
            result += (result.empty() ? "" : " ") + word;
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "the sky is blue";

    string result = sol.reverseEachWord(s);
    cout << "Reversed Each Word: " << result << endl;

    return 0;
}