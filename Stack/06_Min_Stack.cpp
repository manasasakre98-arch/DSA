// File: 06_Min_Stack.cpp
// Stack supporting push, pop, top, and getMin() all in O(1) time

#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; // stores actual values
    stack<int> minStack;  // stores current minimum at each stack level

public:
    // Push value onto stack, tracking the minimum alongside it
    void push(int x) {
        mainStack.push(x);

        // if minStack is empty or x is a new minimum, push x again
        // otherwise, repeat the current minimum
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            minStack.push(minStack.top());
        }
    }

    // Remove the top element from both stacks
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }

    // Return the top element of the main stack
    int top() {
        return mainStack.top();
    }

    // Return the current minimum in O(1)
    int getMin() {
        return minStack.top();
    }

    // Check if stack is empty
    bool isEmpty() {
        return mainStack.empty();
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top: " << st.top() << endl;         // 2
    cout << "Min: " << st.getMin() << endl;       // 2

    st.pop();
    cout << "After pop, Top: " << st.top() << endl;   // 7
    cout << "After pop, Min: " << st.getMin() << endl; // 3

    st.pop();
    cout << "After pop, Top: " << st.top() << endl;   // 3
    cout << "After pop, Min: " << st.getMin() << endl; // 3

    return 0;
}