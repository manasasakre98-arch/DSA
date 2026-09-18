// File: 01_Implement_Singly_Linked_List.cpp
// Basic singly linked list with insert, display, and search operations

#include <iostream>
using namespace std;

// Node structure representing a single element in the list
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning of the list
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);

        // if list is empty, new node becomes the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Print all elements in the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Search for a value in the list, return true if found
    bool search(int x) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);

    cout << "List: ";
    list.display();   // 5 -> 10 -> 20 -> 30

    cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (list.search(100) ? "Found" : "Not Found") << endl;

    return 0;
}