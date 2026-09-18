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
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
   }

   Node* findMiddle(){
    if(head == nullptr){
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
   }

   void display(){
    if(head == nullptr){
        cout << "List is empty" <<endl;
        return;
    }

    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data;
        if(temp->next != nullptr) cout << " -> ";
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
    SinglyLinkedList oddList;
    oddList.insertAtEnd(10);
    oddList.insertAtEnd(20);
    oddList.insertAtEnd(30);
    oddList.insertAtEnd(40);
    oddList.insertAtEnd(50);

    cout << "Odd-length list: ";
    oddList.display();

    Node* oddMiddle = oddList.findMiddle();
    cout << "Middle node: " << (oddMiddle ? to_string(oddMiddle->data) : "None") << endl;

    SinglyLinkedList evenList;
    evenList.insertAtEnd(10);
    evenList.insertAtEnd(20);
    evenList.insertAtEnd(30);
    evenList.insertAtEnd(40);
    

    cout << "Even-length list: ";
    evenList.display();

    Node* evenMiddle = evenList.findMiddle();
    cout << "Middle node: " << (evenMiddle ? to_string(evenMiddle->data) : "None") << endl;

    return 0;
}