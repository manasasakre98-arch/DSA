# Sorting in C++

This folder contains fundamental sorting programs implemented in C++ for DSA practice, interview preparation, and placement preparation.

The goal is to understand the logic behind sorting algorithms instead of simply using built-in functions.

---

## 📚 Programs Covered

| No. | Program | Concept |
|---|---|---|
| 01 | Bubble Sort | Repeatedly swap adjacent elements |
| 02 | Selection Sort | Select minimum element and place it correctly |
| 03 | Insertion Sort | Insert each element into its correct position |
| 04 | Check Array Sorted | Check whether an array is sorted |
| 05 | Sort Array Ascending | Sort from smallest to largest |
| 06 | Sort Array Descending | Sort from largest to smallest |

---

## 1. Bubble Sort

### Idea

Compare adjacent elements and swap them if they are in the wrong order.

After every pass, the largest unsorted element moves to the end.

### Complexity

- Best: O(n) with optimization
- Average: O(n²)
- Worst: O(n²)
- Space: O(1)

### Properties

- Stable
- In-place
- Adaptive when optimized

---

## 2. Selection Sort

### Idea

Find the smallest element from the unsorted portion and place it at the beginning.

### Complexity

- Best: O(n²)
- Average: O(n²)
- Worst: O(n²)
- Space: O(1)

### Properties

- In-place
- Not stable
- Not adaptive
- Performs fewer swaps than Bubble Sort

---

## 3. Insertion Sort

### Idea

Take one element at a time and insert it into its correct position among the already sorted elements.

Similar to arranging playing cards in your hand.

### Complexity

- Best: O(n)
- Average: O(n²)
- Worst: O(n²)
- Space: O(1)

### Properties

- Stable
- In-place
- Adaptive
- Efficient for nearly sorted arrays

---

## 4. Check if Array is Sorted

Compare every element with the next element.

For ascending order:

```cpp
arr[i] <= arr[i + 1]