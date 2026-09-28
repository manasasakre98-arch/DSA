/* 
Q2) Detect and Remove a Loop in a Linked List
    Example: Input: Linked List with a loop
             Output: Loop removed

    "After slow and fast meet, send slow back to head. Then move both one step at a time. Where they meet again = loop start.
    Catch → Locate → Cut"

Time Complexity: O(n): detection, start-finding and cutting are each a linear pass.

Space Complexity: O(1): only pointer variables.
*/

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//returns true if a loop was found and removed
bool detectAndRemoveLoop(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    //Step 1:detect loop using Floyd's slow/fast pointers
    while(fast != nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(fast == nullptr || fast->next == nullptr) return false; //no loop

    //Step 2:find the loop start node
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* loopStart = slow;

    //Step 3: find the last node of the loop and cut its link
    ListNode* last = loopStart;
    while(last->next != loopStart){
        last = last->next;
    }
    last->next = nullptr;

    return true;
}

int main(){
    //build list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    ListNode* tail = head;
    ListNode* loopNode = nullptr;
    for(int i=2; i<=5; i++){
        tail->next = new ListNode(i);
        tail = tail->next;
        if(i == 3) loopNode = tail;
    }
    tail->next = loopNode;  //create loop: 5->3

    if(detectAndRemoveLoop(head))
      cout << "Loop removed" << endl;
    else
      cout << "No loop found" << endl;

    //print and free the list (safe now that the loop is gone)
    while(head != nullptr){
        cout << head->val << (head->next ? "->" : "");
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    cout << endl;

    return 0;
}