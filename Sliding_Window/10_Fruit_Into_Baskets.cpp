/*
Time Complexity: O(n): each pointer moves forward at most n times, and map operations are O(1) average on a map of at most 3 entries.

Space Complexity: O(1): the map never holds more than 3 types.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;   // fruit type -> count in window
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            // more than 2 types: shrink from the left
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {1, 2, 3, 2, 2};

    int result = sol.totalFruit(fruits);
    cout << "Maximum Fruits: " << result << endl;   // 4

    return 0;
}