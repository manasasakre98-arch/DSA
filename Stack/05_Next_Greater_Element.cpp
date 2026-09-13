// File: 05_Next_Greater_Element.cpp
// Find the next greater element for each array element using a monotonic stack

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);

    if (n == 0) return result;

    stack<int> st;  // stores indices; values kept in decreasing order

    // traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // remove elements from stack that are <= current element
        // (they can't be the "next greater" for anything to their left)
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // if stack is not empty, top is the next greater element
        if (!st.empty()) {
            result[i] = arr[st.top()];
        }

        // push current index for elements to its left to check against
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> result = nextGreaterElement(arr);

    cout << "Input:  [";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i + 1 < arr.size() ? ", " : "");
    }
    cout << "]" << endl;

    cout << "Output: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i + 1 < result.size() ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}