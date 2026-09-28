/*
Q2) Reverse Words in a String
    Example: Input: "the sky is blue" 
             Output: "blue is sky the"

    "Take the next word and put it IN FRONT of everything I've already collected."

Time Complexity: O(n²) in the worst case
- Each new word is placed before the existing result.
- This can repeatedly copy the growing result string.

Space Complexity: O(n)
- The input string and output result require O(n) space.
*/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution{
public:
   string reverseWords(string s){
    istringstream iss(s);
    string word, result;

    while(iss >> word){
        result = word + (result.empty() ? "" : " " + result);
    }
    return result;
   }
};

int main(){
    Solution sol;
    string s = "the sky is blue";;

    string result = sol.reverseWords(s);
    cout << "Reversed :" << result << endl;

    return 0;
}