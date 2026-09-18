#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList{
private:
   Node* head;

public:
   SinglyLinkedList(){
    head = nullptr;
   }

   void insertAtEnd(int x){
    Node* newNode = new Node(x);

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
   }

   void reverse(){
    Node* previous = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while(current != nullptr){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head =previous;
   }

   void display(){
    if(head == nullptr){
        cout << "List is empty "<<endl;
        return;
    }

    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data;
        if(temp->next != nullptr) cout<<" -> ";
        temp = temp->next;
    }
    cout << endl;
   }

   ~SinglyLinkedList(){
    Node* temp = head;
    while(temp != nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
   }
};

int main(){
    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original list: ";
    list.display();

    list.reverse();

    cout << "Reversed list: ";
    list.display();

    return 0;
}