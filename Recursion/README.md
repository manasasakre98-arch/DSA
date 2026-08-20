# Recursion — Patterns & Notes

## Core Idea
A function solves a problem by calling itself on a *smaller* version of the
same problem, until a **base case** is hit that can be answered directly
(no further calls needed).

## Call Stack Mental Model
- Each recursive call pauses and waits for the call it made to return.
- This "waiting" is because of a data dependency — you often can't compute
  something (like `n + recurse(n-1)`) until the recursive call resolves.
- Base case is always hit FIRST (deepest point), then the stack "unwinds"
  back up, resolving any pending work along the way.

---

## Problems Solved

### 1. Print 1 to N
- Base case: `if (n == 0) return;`
- Print happens **AFTER** the recursive call.
- Why: recursion goes all the way down to the base case first (no printing
  yet), then prints happen on the way back up — smallest number first →
  increasing order.

### 2. Print N to 1
- Base case: `if (n == 0) return;`
- Print happens **BEFORE** the recursive call.
- Why: each number prints immediately as we go down, before going smaller
  → decreasing order. No pending work after the call returns.

### 3. Sum of First N Numbers
- Base case: `if (n == 0) return 0;`
- Recursive case: `return n + sum(n - 1);`
- Base case is `0` because 0 is the **identity value for addition**
  (adding 0 changes nothing).

### 4. Factorial of N
- Base case: `if (n == 0) return 1;`
- Recursive case: `return n * factorial(n - 1);`
- Base case is `1` because 1 is the **identity value for multiplication**
  (multiplying by 0 would collapse everything to 0, which is wrong since
  0! = 1).

---

## Key Pattern to Remember (not code!)

| Behavior wanted        | Print/compute placement      |
|-------------------------|-------------------------------|
| Top-down / decreasing   | BEFORE recursive call         |
| Bottom-up / increasing  | AFTER recursive call          |

| Operation | Base case (identity value) |
|-----------|------------------------------|
| Addition (+)       | 0 |
| Multiplication (×) | 1 |

## Common Mistakes I Made (and fixed)
- Forgot base case must return a *value* if function return type is `int`
  (not just `return;`)
- Used `return 0` as base case for factorial — wrongly collapses result to 0
- Mismatched function name when calling it in `main()`
- Forgot `cout` when calling a function that *returns* a value — the
  return value alone doesn't print itself

## Complexity (all problems above)
- Time: O(n) — one call per step from n down to 0
- Space: O(n) — call stack holds n frames at the deepest point