// File: 02_Insert_Delete_Node.cpp
// Singly linked list with insert and delete operations (1-based indexing)

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

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a new node at a given 1-based position
    void insertAtPosition(int x, int position) {
        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(x);
            return;
        }

        Node* temp = head;
        // move to the node just before the target position
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete the first node of the list
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete the last node of the list
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        // only one node in the list
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete the node at a given 1-based position
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        // move to the node just before the one to delete
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
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

    // Destructor: free all dynamically allocated nodes
    ~SinglyLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    cout << "After inserting 10, 20, 30 at end: ";
    list.display();

    list.insertAtBeginning(5);
    cout << "After inserting 5 at beginning: ";
    list.display();

    list.insertAtPosition(15, 3);
    cout << "After inserting 15 at position 3: ";
    list.display();

    list.deleteAtBeginning();
    cout << "After deleting at beginning: ";
    list.display();

    list.deleteAtEnd();
    cout << "After deleting at end: ";
    list.display();

    list.deleteAtPosition(2);
    cout << "After deleting at position 2: ";
    list.display();

    return 0;
}
