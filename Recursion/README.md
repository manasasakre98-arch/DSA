# Recursion — Patterns & Notes

## Core Idea
A function solves a problem by calling itself on a *smaller* version of the
same problem, until a **base case** is hit that can be answered directly.

## Call Stack Mental Model
- Each recursive call pauses and waits for the call it made to return
  (data dependency — e.g., can't compute `n + recurse(n-1)` until the
  recursive call resolves).
- Base case hits first (deepest point), then the stack "unwinds" back up,
  resolving pending work along the way.

---

## Problems Solved

### 1. Print 1 to N
- Base case: `if (n == 0) return;`
- Print **AFTER** recursive call → smallest number resolves first on
  unwind → increasing order.

### 2. Print N to 1
- Base case: `if (n == 0) return;`
- Print **BEFORE** recursive call → prints immediately during descent →
  decreasing order. No pending work after call returns.

### 3. Sum of First N Numbers
- Base case: `if (n == 0) return 0;`
- Recursive case: `return n + sum(n - 1);`
- Base case = 0 → **identity value for addition**.

### 4. Factorial of N
- Base case: `if (n == 0) return 1;`
- Recursive case: `return n * factorial(n - 1);`
- Base case = 1 → **identity value for multiplication**
  (0 would collapse everything to 0, which is wrong since 0! = 1).

### 5. Power of a Number (x^n)
- Base case: `if (n == 0) return 1;`
- Recursive case: `return x * power(x, n - 1);`
- Key difference: **x stays FIXED, only n shrinks** — unlike factorial
  where the shrinking value itself is what's multiplied.
- Edge case: negative `n` → infinite recursion / stack overflow, since
  `n` decrements away from 0, never hitting the base case. (Fix requires
  `if (n < 0) return 1.0 / power(x, -n);` with a `double` return type.)

### 6. Sum of Digits
- Base case: `if (n == 0) return 0;`
- Recursive case: `return (n % 10) + sumOfDigits(n / 10);`
- **New shrinking mechanism**: not `n-1`, but removing digits via
  `n / 10` (remaining number) and `n % 10` (last digit).
- Number of calls = number of digits (d), NOT the value of n — this
  changes the complexity class entirely.

---

## Key Patterns to Remember (not code!)

| Behavior wanted        | Print/compute placement      |
|-------------------------|-------------------------------|
| Top-down / decreasing   | BEFORE recursive call         |
| Bottom-up / increasing  | AFTER recursive call          |

| Operation을     | Base case (identity value) |
|-----------------|------------------------------|
| Addition (+)       | 0 |
| Multiplication (×) | 1 |

| Shrinking style        | Used in                          |
|--------------------------|-----------------------------------|
| `n - 1`                 | print, sum, factorial, power (exponent) |
| `n / 10`, `n % 10`      | sum of digits (digit-based problems) |

## Common Mistakes I Made (and fixed)
- Forgot base case must return a *value* if function return type is `int`
- Used `return 0` as base case for factorial — wrongly collapses to 0
- Mismatched function name when calling in `main()`
- Forgot `cout` when calling a function that *returns* a value
- Confused `n-1` shrinking with `n/10` digit-removal shrinking
- Didn't consider negative-input edge cases (infinite recursion risk)

## Complexity Summary
| Problem | Time | Space |
|---|---|---|
| Print 1toN / Nto1 | O(n) | O(n) |
| Sum of first N | O(n) | O(n) |
| Factorial | O(n) | O(n) |
| Power(x,n) | O(n) | O(n) |
| Sum of Digits | O(d), d=digits | O(d) |