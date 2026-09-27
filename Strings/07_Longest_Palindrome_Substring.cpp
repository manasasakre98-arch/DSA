/*
Q1) Longest Palindrome Substring
    Example: Input: "babad" Output: "bab" or "aba"

    "You stand at every possible center → look left and right → if they match, keep expanding → remember the biggest symmetric group.
     That's Expand Around Center."

1. Every palindrome has a center.

2. Odd palindrome → center is one character: (i, i).

3. Even palindrome → center is between characters: (i, i+1).

4. Expand outward while left and right characters match.

5. Keep the longest palindrome found so far.

Time Complexity: O(n²) — n centers, each expansion up to O(n) in the worst case.

Space Complexity: O(1) — no extra data structure beyond a few tracking variables.
*/

#include<iostream>
#include<string>
using namespace std;

class Solution{
private:
   void expand(const string& s, int left, int right, int& start, int& maxLen){
    while(left >=0 && right <s.size() && s[left] == s[right]){
        left--;
        right++;
    }
    int len = right - left - 1;
    if(len > maxLen){
        maxLen = len;
        start = left + 1;
    }
   }

public:
   string longestPalindrome(string s){
    if(s.empty()) return "";

    int start = 0, maxLen = 1;

    for(int i = 0; i < s.size(); i++){
        expand(s, i, i, start, maxLen);  //odd-length palindrome
        expand(s, i, i+1, start, maxLen);  //even-length palindrome
    }

    return s.substr(start, maxLen);
   }
};

int main(){
    Solution sol;
    string s = "babad";

    string result = sol.longestPalindrome(s);
    cout << "Longest Palindrome Substing: " << result << endl;

    return 0;
}