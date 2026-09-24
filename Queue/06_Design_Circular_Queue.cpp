// File: 06_Design_Circular_Queue.cpp

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int front;
    int count;      // current number of elements
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        front = 0;
        count = 0;
        capacity = k;
    }

    // insert an element at the rear of the queue
    bool enQueue(int value) {
        if (isFull()) return false;

        int rearIndex = (front + count) % capacity;
        data[rearIndex] = value;
        count++;
        return true;
    }

    // remove an element from the front of the queue
    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % capacity;
        count--;
        return true;
    }

    // get the front element
    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }

    // get the rear element
    int Rear() {
        if (isEmpty()) return -1;

        int rearIndex = (front + count - 1) % capacity;
        return data[rearIndex];
    }

    // check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // check if the queue is full
    bool isFull() {
        return count == capacity;
    }
};

int main() {
    MyCircularQueue cq(3);

    cout << "enQueue(1): " << (cq.enQueue(1) ? "true" : "false") << endl; // true
    cout << "enQueue(2): " << (cq.enQueue(2) ? "true" : "false") << endl; // true
    cout << "enQueue(3): " << (cq.enQueue(3) ? "true" : "false") << endl; // true
    cout << "enQueue(4): " << (cq.enQueue(4) ? "true" : "false") << endl; // false, queue full

    cout << "Rear: " << cq.Rear() << endl;   // 3
    cout << "isFull: " << (cq.isFull() ? "true" : "false") << endl; // true

    cout << "deQueue(): " << (cq.deQueue() ? "true" : "false") << endl; // true
    cout << "enQueue(4): " << (cq.enQueue(4) ? "true" : "false") << endl; // true

    cout << "Front: " << cq.Front() << endl; // 2
    cout << "Rear: " << cq.Rear() << endl;   // 4

    cout << "isEmpty: " << (cq.isEmpty() ? "true" : "false") << endl; // false

    return 0;
}

// Time Complexity:
// enQueue: O(1)
// deQueue: O(1)
// Front: O(1)
// Rear: O(1)
// isEmpty: O(1)
// isFull: O(1)
//
// Space Complexity: O(k) - fixed-size array of capacity k