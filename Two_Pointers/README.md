# Two Pointers — Patterns & Notes

## Two Main Patterns

### Opposite-Direction Pointers
- left = 0, right = n-1, move toward each other
- Used when array is sorted, or checking from both ends
- Examples: Reverse Array, Palindrome Check, Two Sum Sorted, Container With Most Water

### Same-Direction Pointers (slow/fast)
- Both start near the beginning; fast scans every element, slow marks a "write position"
- Used for in-place filtering/rearranging
- Examples: Remove Duplicates, Move Zeroes

---

## Problems Solved

### 1. Reverse Array
- left=0, right=n-1, while(left<right): swap(arr[left],arr[right]), left++, right--

### 2. Check Palindrome
- Same pointer setup as reverse
- if (str[left] != str[right]) return false  <- early exit on failure
- return true only AFTER loop completes (late success)
- Rule: "Return false early, return true late"

### 3. Two Sum in Sorted Array
- sum < target -> left++ (need bigger value)
- sum > target -> right-- (need smaller value)
- ONLY works on sorted arrays — sortedness guarantees direction of change

### 4. Remove Duplicates from Sorted Array
- slow=0, fast=1 (index 0 trivially valid)
- if arr[fast] != arr[slow]: slow++, arr[slow]=arr[fast]
- fast moves every iteration; slow moves only when new unique value found

### 5. Move Zeroes
- slow=-1, fast=0 (nothing guaranteed valid at start, unlike Remove Duplicates)
- if arr[fast] != 0: slow++, arr[slow]=arr[fast]
- AFTER main loop: second loop fills remaining positions with 0
- Mental model: slow = "next empty box" pointer; slow++ happens BEFORE placing value

### 6. Container With Most Water ⭐
- left=0, right=n-1
- area = (right-left) * min(arr[left], arr[right])
- ALWAYS move the pointer at the SHORTER line
- Why: moving the taller line can only shrink width with no height improvement
  (provably useless); moving shorter line gives a CHANCE at better height

---

## Key Patterns to Remember (not code!)

| Problem type | Pointer start | Movement rule |
|---|---|---|
| Reverse/Palindrome | left=0, right=n-1 | swap/compare, move both inward |
| Two Sum Sorted | left=0, right=n-1 | move based on sum vs target |
| Remove Duplicates | slow=0, fast=1 | slow moves on new unique value |
| Move Zeroes | slow=-1, fast=0 | slow moves on non-zero value |
| Container w/ Water | left=0, right=n-1 | move the SHORTER line |

## Common Mistakes I Made (and fixed)
- Comparing pointer INDICES instead of the VALUES at those indices
- Returning true/false at the wrong point in the loop (early vs late exit)
- Confusing slow's starting position (0 vs -1) — depends on whether index 0
  is guaranteed valid at the start
- Forgetting the second cleanup loop in Move Zeroes
- Moving the wrong pointer in Container With Most Water (taller instead of shorter)

## Complexity Summary
| Problem | Time | Space |
|---|---|---|
| Reverse Array | O(n) | O(1) |
| Palindrome Check | O(n) | O(1) |
| Two Sum Sorted | O(n) | O(1) |
| Remove Duplicates | O(n) | O(1) |
| Move Zeroes | O(n) | O(1) |
| Container With Most Water | O(n) | O(1) |