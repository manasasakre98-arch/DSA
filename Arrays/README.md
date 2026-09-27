# Arrays — C++ DSA

Arrays are one of the most fundamental data structures in programming — a contiguous block of memory used to store elements of the same type. Almost every interview and placement round starts here, since arrays form the base for more advanced topics like searching, sorting, prefix sums, two pointers, and sliding window techniques.

This section contains my practice implementations of common array-based problems in C++. Each file focuses on a specific concept, with clean, working code meant for understanding and revision — not just solving the problem once and moving on.

## Topics Covered

| Problem | Concept | Time Complexity | Space Complexity |
|---|---|---|---|
| `01_Array_Input_Output.cpp` | Taking array input and printing it | O(n) | O(1) |
| `02_Array_Traversal.cpp` | Basic array traversal | O(n) | O(1) |
| `03_Sum_of_Elements.cpp` | Sum of all elements | O(n) | O(1) |
| `04_Largest_Element.cpp` | Finding the largest element | O(n) | O(1) |
| `05_Smallest_Element.cpp` | Finding the smallest element | O(n) | O(1) |
| `06_Max_Min.cpp` | Finding max and min together | O(n) | O(1) |
| `07_Average.cpp` | Average of array elements | O(n) | O(1) |
| `08_Linear_Search.cpp` | Searching for an element | O(n) | O(1) |
| `09_Kadane_Algorithm.cpp` | Maximum subarray sum | O(n) | O(1) |
| `10_Rotate_by_K.cpp` | Rotating array by k positions | O(n) | O(1) |

## Key Concepts

- **Array Traversal** — Visiting every element exactly once, usually with a single loop. The base pattern almost every array problem builds on.
- **Searching** — Checking elements one by one (linear search) to find a target value or its position.
- **Finding Min/Max** — Keeping track of the smallest/largest value seen so far while traversing, instead of comparing every pair of elements.
- **Running Sums** — Accumulating a total (or average) as you move through the array, rather than recalculating from scratch each time.
- **Kadane's Algorithm** — An approach to find the maximum sum subarray by deciding, at each step, whether to extend the current subarray or start fresh.
- **Array Rotation** — Shifting elements left or right by `k` positions, either using extra space or in-place using the reversal trick.
- **Time and Space Complexity** — Understanding not just whether a solution works, but how it scales with input size and how much extra memory it uses.

## Important Patterns

- **Single-pass traversal** — Solving a problem while going through the array only once.
- **Maintaining a running value** — Carrying forward a sum, max, or min as you traverse instead of recomputing it.
- **Comparing current and best answers** — Updating a "best so far" variable (like max sum or max element) at every step.
- **Reversing an array for rotation** — Using reversal as a building block to achieve rotation without extra space.
- **O(n) vs O(1) reasoning** — Recognizing that most of these problems require visiting every element (O(n) time), while the extra memory used often stays constant (O(1) space).

## Complexity Summary

Most basic array problems here are **O(n)** because they require looking at every element at least once — there's no way to guarantee correctness (like finding a sum, max, or min) without checking each value. 

**O(1) auxiliary space** means the extra memory used doesn't grow with the input size. A few variables (like a sum, a max, or a loop counter) are used regardless of whether the array has 10 elements or 10,000 — the input array itself isn't counted as "extra" space.

## Learning Notes

For `09_Kadane_Algorithm.cpp`:
> If the previous sum helps, carry it forward. If it hurts, restart.

This is the core idea behind Kadane's Algorithm — at each element, you decide whether continuing the existing subarray is better than starting a new one from the current element.

For `10_Rotate_by_K.cpp`, the three-reversal idea:
1. Reverse the entire array.
2. Reverse the first `k` elements.
3. Reverse the remaining `n - k` elements.

This achieves an in-place rotation in O(n) time and O(1) space, without needing a separate array to hold rotated values.

## Practice Progress

- [x] Array Input/Output
- [x] Array Traversal
- [x] Sum of Elements
- [x] Largest Element
- [x] Smallest Element
- [x] Max and Min
- [x] Average of Elements
- [x] Linear Search
- [x] Kadane's Algorithm
- [x] Rotate Array by K

## What's Next

With these fundamentals covered, the natural next steps are:

- **Prefix Sum** — Precomputing cumulative sums for faster range queries.
- **Two Pointers** — Using two indices moving through the array to solve problems more efficiently.
- **Sliding Window** — Tracking a subarray of variable or fixed size while traversing.
- **Binary Search** — Searching in sorted arrays in O(log n) time.
- **Hashing** — Using hash maps/sets to solve array problems in fewer passes.
- **More array interview problems** — Covering patterns like sorting-based problems, subarray problems, and array manipulation questions commonly asked in placements.

## Repository Philosophy

**Understand → Implement → Analyze Complexity → Practice Again**

---

*This repository is being built progressively as part of ongoing DSA and placement preparation.*