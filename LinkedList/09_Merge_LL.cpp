/*
Q3) Merge two Sorted Linked Lists
    Example: Input: 1->2->4, 1->3->4
             Output:1->1->2->3->4->4
    
    "Compare two heads → take the smaller → attach it to tail → move that list → move tail → repeat → attach the leftover."

Time Complexity: O(n + m), where n and m are the list lengths.

Space Complexity: O(1): existing nodes are relinked, and no new nodes are created during the merge.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        //attach whichever list still has nodes left
        tail->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};

//helper to build a list from an array
ListNode* buildList(const int arr[], int n){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i=0;i<n;i++){
        ListNode* node = new ListNode(arr[i]);
        if(head == nullptr) head = tail = node;
        else{ tail->next = node; tail = node; }
    }
    return head;
}

int main(){
    Solution sol;

    int a[] = {1, 2, 4};
    int b[] = {1, 3, 4};
    ListNode* list1 = buildList(a, 3);
    ListNode* list2 = buildList(b, 3);

    ListNode* merged = sol.mergeTwoLists(list1, list2);

    //print and free the merged list
    while(merged != nullptr){
        cout << merged->val << (merged->next ? "->" : "");
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }
    cout << endl;
    return 0;
}