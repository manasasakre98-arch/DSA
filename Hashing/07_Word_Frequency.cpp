/*
Time Complexity: O(n) — n total characters across all words; each word insertion/lookup is O(1) average with hashing.

Space Complexity: O(k) — k unique words stored in the map.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, int> wordFrequency(string s) {
        unordered_map<string, int> freq;
        istringstream iss(s);
        string word;

        while (iss >> word) {
            freq[word]++;
        }

        return freq;
    }
};

int main() {
    Solution sol;
    string s = "the sky is blue the sun is bright";

    unordered_map<string, int> result = sol.wordFrequency(s);

    for (const auto& pair : result) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}