// Problem 1: Implement Stack using Array

// Problem Statement: Implement a Stack data structure from scratch using a fixed-size array, supporting push, pop, top/peek, isEmpty, and isFull operations.

// Example:

// push(10) -> stack: [10]
// push(20) -> stack: [10, 20]
// top()    -> 20
// pop()    -> stack: [10]
// isEmpty() -> false

// Optimal Approach: Use an array with a top index variable tracking the current top position (-1 when empty). All operations are O(1) since we only ever touch the end of the array.

// Algorithm:

// push: check if full; if not, increment top, place value at arr[top]
// pop: check if empty; if not, return arr[top], decrement top
// peek: check if empty; return arr[top]
// isEmpty: top == -1
// isFull: top == capacity - 1

// Time Complexity: All operations (push, pop, peek, isEmpty, isFull) are O(1) — direct array index access, no traversal.

// Space Complexity: O(n) where n = capacity, for the underlying array.

// Edge Cases:

// Popping/peeking from an empty stack (handled with isEmpty() check)
// Pushing onto a full stack (handled with isFull() check)
// Stack of size 0 or 1

// #include <iostream>
// using namespace std;

// class Stack {
// private:
//     int* arr;       // underlying array
//     int capacity;   // max size of stack
//     int top;        // index of the top element (-1 when empty)

// public:
//     // Constructor: allocate array of given size
//     Stack(int size) {
//         capacity = size;
//         arr = new int[capacity];
//         top = -1;
//     }

//     // Destructor: free allocated memory
//     ~Stack() {
//         delete[] arr;
//     }

//     // Push an element onto the stack
//     void push(int value) {
//         if (isFull()) {
//             cout << "Stack Overflow: cannot push " << value << endl;
//             return;
//         }
//         arr[++top] = value;   // increment top, then place value
//     }

//     // Remove and return the top element
//     int pop() {
//         if (isEmpty()) {
//             cout << "Stack Underflow: cannot pop" << endl;
//             return -1;         // sentinel value for empty stack
//         }
//         return arr[top--];    // return current top, then decrement
//     }

//     // Return the top element without removing it
//     int peek() {
//         if (isEmpty()) {
//             cout << "Stack is empty" << endl;
//             return -1;
//         }
//         return arr[top];
//     }

//     // Check if stack is empty
//     bool isEmpty() {
//         return top == -1;
//     }

//     // Check if stack is full
//     bool isFull() {
//         return top == capacity - 1;
//     }

//     // Return current number of elements
//     int size() {
//         return top + 1;
//     }
// };

// int main() {
//     Stack st(5);   // create stack with capacity 5

//     st.push(10);
//     st.push(20);
//     st.push(30);

//     cout << "Top element: " << st.peek() << endl;   // 30
//     cout << "Popped: " << st.pop() << endl;          // 30
//     cout << "Top element after pop: " << st.peek() << endl; // 20
//     cout << "Stack size: " << st.size() << endl;      // 2
//     cout << "Is empty? " << (st.isEmpty() ? "Yes" : "No") << endl; // No

//     return 0;
// }

#include<iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int capacity;
        int top;


public:
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack(){
        delete[] arr;
    }

    void push(int value){
        if(isFull()){
            cout << "Stack Overflow: cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow: cannot pop" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
    }

    int size(){
        return top + 1;
    }

};

int main(){
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Top element after pop: " << st.peek() << endl;
    cout << "Stack size: " << st.size() << endl;
    cout << "Is empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}





