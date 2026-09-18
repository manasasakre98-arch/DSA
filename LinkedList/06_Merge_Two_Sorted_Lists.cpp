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

void insertAtEnd(Node*& head, int x){
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

void display(Node* head){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data;
        if(temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

Node* mergeSortedLists(Node* head1, Node* head2){
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;

    Node dummy(0);
    Node* tail = &dummy;

    Node* p1 = head1;
    Node* p2 = head2;

    while(p1 != nullptr && p2 != nullptr){
        if(p1->data <= p2->data){
            tail->next = p1;
            p1 = p1->next;
        }else{
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }
    tail->next = (p1 != nullptr) ? p1 : p2;

    return dummy.next;
}

void clear(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

int main(){
    Node* list1 = nullptr;
    insertAtEnd(list1, 1);
    insertAtEnd(list1, 3);
    insertAtEnd(list1, 5);
    insertAtEnd(list1, 7);

    Node* list2 = nullptr;
    insertAtEnd(list2, 2);
    insertAtEnd(list2, 4);
    insertAtEnd(list2, 6);

    cout<<"List 1: ";
    display(list1);

    cout<<"List 2: ";
    display(list2);

    Node* mergedHead = mergeSortedLists(list1, list2);

    cout << "Merged list: ";
    display(mergedHead);

    clear(mergedHead);

    return 0;
}