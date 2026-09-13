# Stack — Patterns & Notes

## Core Idea
Stack follows LIFO (Last In, First Out) — the most recently added element
is the first one removed. Only the top is accessible; no direct access to
middle or bottom elements.

---

## Problems Solved

### 1. Implement Stack using Array
- Manual implementation using a fixed-size array + `top` index (-1 when empty)
- push: `arr[++top] = value` (increment first, then place)
- pop: `arr[top--]` (return first, then decrement)
- Must manually check `isFull()` before push, `isEmpty()` before pop/peek
- Time: O(1) all operations | Space: O(n) — fixed capacity array

### 2. Stack using STL (std::stack)
- Container adapter, defaults to `std::deque` internally
- `push()`, `pop()` (returns void!), `top()`, `empty()`, `size()`
- No manual overflow handling — resizes automatically
- KEY TRAP: `pop()` returns nothing — must call `top()` BEFORE `pop()`
  if you need the removed value
- Time: O(1) all operations | Space: O(n) — dynamic, no fixed capacity

### 3. Valid Parentheses
- Push opening brackets `( { [`
- On closing bracket: check `stack.empty()` first (avoid undefined behavior),
  then check `stack.top()` matches the correct opening type
- At the end: valid only if stack is fully empty (no unmatched opens)
- WHY STACK: LIFO naturally enforces "innermost closes first" —
  a simple counter can't catch wrong ORDER (e.g., "([)]")
- Time: O(n) | Space: O(n) — worst case all opening brackets

### 4. Reverse a Stack (Recursion)
- Two functions: `reverseStack()` (main) + `insertAtBottom()` (helper)
- `reverseStack`: pop top, recursively reverse the rest, then insertAtBottom
  the held value into the now-reversed remainder
- `insertAtBottom`: recursively pop everything until empty (true bottom),
  push new value there, then restore popped elements on the way back up
- Base case for both: `stack.empty()`
- Uses call stack itself as implicit storage — no explicit extra structure
- Time: O(n²) — n calls to reverseStack, each triggering O(n) insertAtBottom
- Space: O(n) — recursive call stack depth

### 5. Next Greater Element (Monotonic Stack)
- Traverse RIGHT TO LEFT, stack holds indices in DECREASING value order
- Before pushing current index: pop all stack elements with
  value <= current (they can never be "next greater" for anything further left)
- If stack non-empty after popping, top = next greater element
- Time: O(n) — each index pushed once, popped at most once
- Space: O(n) — worst case (strictly decreasing array keeps everything on stack)

### 6. Min Stack
- TWO stacks: mainStack (actual values) + minStack (running minimum at each level)
- On push: minStack pushes new value if it's a new min, else repeats current min
- This keeps mainStack and minStack always the SAME SIZE, so pop() is symmetric
- getMin() = O(1) lookup of minStack.top(), no scanning needed
- Time: O(1) all operations | Space: O(n) — two parallel stacks

---

## Key Patterns to Remember (not code!)

| Problem type | Core technique |
|---|---|
| Bracket/nesting validation | Push opens, match-check closes against top, empty check at end |
| Reverse using recursion | Call stack as implicit storage; helper function for "insert at bottom" |
| Next greater/smaller element | Monotonic stack, traverse from the end, pop while condition fails |
| Track running min/max alongside stack | Parallel second stack, synced push/pop, no recalculation needed |

## Common Mistakes I Made (and fixed)
- Forgetting `std::stack::pop()` returns void — must call `top()` first if value is needed
- Not checking `stack.empty()` before `top()`/`pop()` — undefined behavior risk
- In Valid Parentheses: forgetting the final `stack.empty()` check
  (catches leftover unmatched opening brackets like "(((")
- In Reverse Stack: confusing when to use `insertAtBottom()` vs. plain `push()`
  (plain push would undo the reversal)
- Underestimating Reverse Stack's complexity as O(n) when it's actually O(n²)
  due to nested recursive calls
- In Min Stack: trying to use a single stack + manual min-tracking variable
  (breaks on pop — can't recover the previous min without a second stack)

## Complexity Summary
| Problem | Time | Space |
|---|---|---|
| Stack via Array | O(1) all ops | O(n) fixed |
| Stack via STL | O(1) all ops | O(n) dynamic |
| Valid Parentheses | O(n) | O(n) |
| Reverse a Stack | O(n²) | O(n) |
| Next Greater Element | O(n) | O(n) |
| Min Stack | O(1) all ops | O(n) |

## Interview Takeaways
- Stack = right choice whenever "most recent unresolved item" matters
  (nesting, backtracking, undo operations, matching pairs)
- Monotonic stack is a distinct, very high-value pattern — reused in
  Next Greater/Smaller Element, histogram problems, stock span problems
- Always know the STL gotchas cold: `pop()` returns void, no bounds checking,
  no iteration support