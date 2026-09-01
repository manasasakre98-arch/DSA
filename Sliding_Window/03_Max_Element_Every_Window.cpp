/*
Problem: Maximum Element in Every Window of Size K (Monotonic Deque)

Algorithm:
1. Use a deque to store INDICES, maintained so values are in DECREASING order
   (front always holds index of current window's maximum)
2. For each new element (right pointer):
   - while back of deque has a SMALLER value than incoming, pop from back
   - push new index to back
3. If front of deque == outgoing index (left), pop from front
4. Once window is full (size k), front of deque = answer for this window

Time Complexity: O(n) — each index pushed at most once, popped at most once
Space Complexity: O(k) — deque holds at most k indices at any time
*/

#include<iostream>
#include<deque>
using namespace std;

void maxOfEveryWindow(int arr[], int n, int k){
    deque<int> dq;

    for(int right = 0;right<n;right++){
        // remove elements from back while they are smaller than current element
        while (!dq.empty() && arr[dq.back()] < arr[right]){
            dq.pop_back();
        }
        
        dq.push_back(right);

        //remove ougoing index from front if it's out of the window
        int left = right - k + 1;
        if(dq.front() < left){
            dq.pop_front();
        }

        //print answer once window is full
        if(right >= k-1){
            cout<<arr[dq.front()]<<" ";
        }
    }
}
int main(){
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int n = 8, k = 3;
    maxOfEveryWindow(arr,n,k);
    return 0;
}