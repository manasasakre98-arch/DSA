/*
Problem: First Negative Number in Every Window of Size K

Algorithm:
1. Use a queue to store INDICES of negative numbers currently in the window
2. For each new element entering (right pointer):
   - if arr[right] < 0, push its index into the queue
3. Once window reaches size k:
   - if front of queue == left (outgoing index), pop it
   - answer for this window = arr[front] if queue not empty, else 0
   - slide window: left++, right++

Time Complexity: O(n) — each index pushed at most once, popped at most once
Space Complexity: O(k) — queue holds at most k indices at any time
*/

#include <iostream>
#include <queue>
using namespace std;

void firstNegativeInWindow(int arr[], int n, int k)
{
    queue<int> q; // stores indices of negative numbers

    // process first window of size k
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            q.push(i);
    }

    for (int right = k; right <= n; right++)
    {
        // print answer for current window
        if (!q.empty())
            cout << arr[q.front()] << " ";
        else
            cout << 0 << " ";

        if (right == n)
            break; // no more elements to process

        int left = right - k;
        // remove outgoing index if it's at the front
        if (!q.empty() && q.front() == left)
            q.pop();

        // add new incoming element if negative
        if (arr[right] < 0)
            q.push(right);
    }
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = 8;
    int k = 3;
    firstNegativeInWindow(arr, n, k);
    return 0;
}
