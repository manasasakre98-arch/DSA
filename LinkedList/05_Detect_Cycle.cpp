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

   Node* getNodeAt(int position){
    Node* temp = head;
    int i = 1;
    while (temp!=nullptr && i<position){
        temp = temp->next;
        i++;
    }
    return temp;
   }

   void createCycle(Node* target){
    if(head == nullptr) return;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = target;
   }

   bool hasCycle(){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
   }

   void display(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data;
        if(temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
   }

   void breakCycleAt(Node* node){
    if(node == nullptr) return;
    node->next = nullptr;
   }

   void clear(){
    Node* temp = head;
    while(temp != nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
   }

   ~SinglyLinkedList(){
    clear();
   }
};

int main(){
    SinglyLinkedList list1;
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);
    list1.insertAtEnd(40);

    cout << "List 1: ";
    list1.display();
    cout << "Has Cycle? " << (list1.hasCycle() ? "Yes" : "No")<<endl;
    
    SinglyLinkedList list2;
    list2.insertAtEnd(1);
    list2.insertAtEnd(2);
    list2.insertAtEnd(3);
    list2.insertAtEnd(4);
    list2.insertAtEnd(5);

    Node* cycleTarget = list2.getNodeAt(2);
    list2.createCycle(cycleTarget);

    cout << "List 2 created with a cycle (5 -> back to 2)"<<endl;
    cout << "Has cycle? " << (list2.hasCycle()? "Yes" : "No")<<endl;

    Node* lastNode = list2.getNodeAt(5);
    list2.breakCycleAt(lastNode);

    return 0;

}