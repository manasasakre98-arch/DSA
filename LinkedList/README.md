# Singly Linked List — Patterns & Notes

## Core Idea
A linked list stores elements as individual Nodes (data + pointer to next),
connected via pointers rather than contiguous memory. Only the `head` is
directly tracked — everything else is reached by following `next` links.

Key trade-off vs arrays:
- O(1) insertion at the head (arrays need shifting — O(n))
- No O(1) random access (must traverse from head to reach any index)

---

## Problems Solved

### 1. Implement a Singly Linked List
- Node { int data; Node* next; }
- insertAtBeginning: O(1) — new node, point to old head, update head
- insertAtEnd: O(n) — traverse to last node (no tail pointer maintained)
- search/display: O(n) — full traversal
- Destructor frees all nodes to avoid memory leaks

### 2. Insert and Delete Nodes (1-based indexing)
- insertAtPosition/deleteAtPosition: walk to the node JUST BEFORE the target
  position, then relink pointers
- Always check for empty list AND invalid position (out of range) separately
- deleteAtEnd needs special case: single-node list (head->next == nullptr)

### 3. Reverse a Singly Linked List (Iterative, In-Place)
- THREE pointers: previous, current, next
- Core loop: save next -> reverse current's pointer -> advance previous
  and current
- head = previous at the end (previous ends up on the last real node)
- No second list created — pure pointer rewiring

### 4. Find the Middle Node (Slow & Fast Pointers / Floyd's)
- slow moves 1 step, fast moves 2 steps
- Loop condition: while (fast != nullptr && fast->next != nullptr)
- When fast reaches the end, slow is naturally at the middle
- Even-length list: this exact condition lands on the SECOND middle node

### 5. Detect Cycle (Floyd's Cycle Detection)
- Same slow/fast setup as Problem 4
- If slow == fast at any point -> cycle exists
- If fast (or fast->next) hits nullptr -> no cycle, loop ends naturally
- CAUTION: display()/destructor would infinite-loop on a cyclic list —
  must break the cycle manually before cleanup in test code

### 6. Merge Two Sorted Linked Lists (Iterative, Node Reuse)
- Dummy node technique: simplifies edge cases, avoids special-casing
  "first node of merged list"
- Compare current nodes of both lists, attach the smaller one, advance
  only that list's pointer
- After one list is exhausted, attach the remainder of the other directly
  (already sorted, no need to process node by node)
- REUSES existing nodes — no new Node() calls during merge, so only
  free the merged list once (avoid double-delete)

---

## Key Patterns to Remember (not code!)

| Problem type | Core technique |
|---|---|
| Insert/delete at position | Walk to node BEFORE target, relink around it |
| Reverse in-place | Three pointers: previous, current, next — no second list |
| Find middle / detect cycle | Slow (1 step) + Fast (2 steps) pointers |
| Merge sorted structures | Dummy node + pick-smaller-and-advance loop |

## Common Mistakes I Made (and fixed)
- Forgetting to check BOTH empty list and invalid position separately
  (they need different messages/handling)
- Off-by-one when walking to "node before position" (loop bound: i < position-1)
- Confusing reverse pointers order — must save `next` BEFORE breaking
  `current->next` link, or the rest of the list is lost
- Not realizing fast pointer's exact stopping condition determines
  WHICH middle node you get for even-length lists
- Attempting display()/delete on a cyclic list without breaking the
  cycle first — causes infinite loop/crash
- Creating brand-new nodes during merge instead of reusing existing ones
  (wastes memory and risks double-deletion bugs)

## Complexity Summary
| Problem | Time | Space |
|---|---|---|
| Insert at beginning | O(1) | O(1) |
| Insert at end / position | O(n) | O(1) |
| Delete at beginning | O(1) | O(1) |
| Delete at end / position | O(n) | O(1) |
| Reverse (iterative) | O(n) | O(1) |
| Find middle (slow/fast) | O(n) | O(1) |
| Detect cycle (Floyd's) | O(n) | O(1) |
| Merge two sorted lists | O(n+m) | O(1) — reuses nodes |

## Interview Takeaways
- Slow/fast pointer technique is a HIGH-VALUE reusable pattern —
  covers middle-finding, cycle detection, and (later) cycle start detection
- Always ask/clarify: "should I create new nodes or reuse existing ones?"
  for merge-type problems — interviewers often want O(1) extra space
- Dummy node is a standard trick to avoid messy head-node special cases
  in insert/merge/delete problems
- Always mention memory management (delete/destructor) even if not asked —
  shows C++ fluency beyond just algorithm logic
- Common follow-up: "How would this change for a DOUBLY linked list?"
  (know that doubly adds O(1) deletion given a node pointer, at the cost
  of extra `prev` pointer memory)