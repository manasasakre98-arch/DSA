/*
Problem: Longest Substring Without Repeating Characters (Variable-size window)

Algorithm:
1. Use unordered_map<char, int> to store each character's LAST SEEN INDEX
2. right pointer expands through the string
3. If s[right] was seen before AND its last index is >= left (still inside window):
   - jump left to (last seen index + 1)
4. Update map with current index for s[right]
5. Track max window length: right - left + 1

Time Complexity: O(n) - each character visited once by right pointer
Space Complexity: O(min(n, charset size)) - map holds at most one entry per unique character
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubstring(string s){
    unordered_map<char, int> lastSeen;
    int left = 0, maxLen = 0;

    for(int right = 0; right <s.length(); right++){
        char c=s[right];

        if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left){
            left = lastSeen[c] + 1;
        }
        lastSeen[c] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main(){
    cout<< longestSubstring("abcabcbb");
    return 0;
}