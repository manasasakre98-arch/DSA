/*
Q1) Reverse a Linked List
    Example: Input: 1->2->3->4->5 
             Output: 5->4->3->2->1
    
    "Linked-list reversal = save next → reverse link → advance previous → advance current."

Time Complexity: O(n): each node visited once.

Space Complexity: O(1): only pointer variables, no extra structure.
*/

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* previous = nullptr;
        ListNode* current = head;

        while(current != nullptr){
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        return previous;
    }
};

int main(){
    Solution sol;

    //build list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    ListNode* tail = head;
    for(int i=2; i<=5;i++){
        tail->next = new ListNode(i);
        tail = tail->next;
    }

    head = sol.reverseList(head);

    //print and free the reversed list
    while(head != nullptr){
        cout << head->val << (head->next ? "->" : "");
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    cout << endl;
    return 0;
}