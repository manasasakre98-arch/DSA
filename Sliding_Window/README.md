# Sliding Window — Fixed-Size Problems (1-3)

## Core Concept
Window = contiguous range of exactly k elements. Slides forward one step
at a time: right expands (always), left moves in lockstep to maintain size k.

## Problems Solved

### 1. Maximum Sum Subarray of Size K
- windowSum += arr[right] - arr[left]  (add incoming, subtract outgoing)
- Initialize maxSum with FIRST window's sum (not 0 — breaks on all-negative arrays)
- O(n) time, O(1) space

### 2. First Negative Number in Every Window of Size K
- Queue of INDICES (not values) of negative numbers in window
- Store indices because duplicate VALUES can't distinguish position
- Front of queue = oldest/smallest index → check if it fell out of window
- Only FRONT ever needs checking (smallest index always falls out first)
- O(n) time, O(k) space

### 3. Maximum Element in Every Window of Size K (Monotonic Deque)
- Deque of indices, values kept in DECREASING order front-to-back
- Before adding new element: WHILE loop pops smaller values from BACK
  (smaller elements become permanently useless once a bigger one arrives)
- Front of deque check: pop if index fell out of window range
- Front = current window's maximum (always)
- O(n) time, O(k) space

## Key Distinctions
| Structure | Add | Remove |
|---|---|---|
| Queue (Problem 2) | back only | front only |
| Deque (Problem 3) | back only | front AND back |

## Common Mistakes
- Forgetting += (writing windowSum = ... instead of windowSum += ...)
- Using IF instead of WHILE for back-popping in monotonic deque
  (multiple elements can be smaller, not just one)
- Storing values instead of indices when duplicates could cause ambiguity
- Confusing negative number comparisons (-1 > -3, not -1 < -3)

## Complexity Summary
| Problem | Time | Space |
|---|---|---|
| Max Sum Subarray | O(n) | O(1) |
| First Negative Number | O(n) | O(k) |
| Max Element (Monotonic Deque) | O(n) | O(k) |