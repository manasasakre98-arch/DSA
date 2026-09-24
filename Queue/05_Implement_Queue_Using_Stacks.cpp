// File: 05_Implement_Queue_Using_Stacks.cpp

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;    // used for push operations
    stack<int> outStack;   // used for pop/peek operations

    // move all elements from inStack to outStack only when outStack is empty
    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {

    }

    // push element to the back of the queue
    void push(int x) {
        inStack.push(x);
    }

    // remove and return the front element of the queue
    int pop() {
        transfer();
        int frontValue = outStack.top();
        outStack.pop();
        return frontValue;
    }

    // return the front element without removing it
    int peek() {
        transfer();
        return outStack.top();
    }

    // check if the queue is empty
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Peek: " << q.peek() << endl;   // 1
    cout << "Pop: " << q.pop() << endl;      // 1
    cout << "Pop: " << q.pop() << endl;      // 2

    q.push(4);
    q.push(5);

    cout << "Peek: " << q.peek() << endl;   // 3
    cout << "Pop: " << q.pop() << endl;      // 3
    cout << "Pop: " << q.pop() << endl;      // 4

    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl; // No

    cout << "Pop: " << q.pop() << endl;      // 5
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}

// Time Complexity:
// push: O(1)
// pop: O(1) amortized (each element moved between stacks at most once)
// peek: O(1) amortized
// empty: O(1)
//
// Space Complexity: O(n) - two stacks together hold all n elements