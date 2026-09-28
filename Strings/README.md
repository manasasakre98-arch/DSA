# Strings — Patterns & Notes

## Core Idea
A string is a sequence of characters that can be indexed like an array
(`s[i]`). Most string problems reduce to one of a few patterns:
traversal, two pointers, frequency counting, or expanding around a center.

---

## Problems Solved

### 1. String Traversal
- Loop with index (`s[i]`) or range-based `for (char c : s)`
- Base skill used by every other problem in this folder
- Time: O(n) | Space: O(1)

### 2. Reverse String
- Two pointers: `left = 0`, `right = n-1`, swap and move inward
- Loop condition: `while (left < right)`
- In-place, no extra string needed
- Time: O(n) | Space: O(1)

### 3. Valid Palindrome
- Two pointers from both ends, compare characters
- Return false early on mismatch, return true only after the loop finishes
- Follow-up: skip non-alphanumeric characters and ignore case
  (`isalnum()`, `tolower()`)
- Time: O(n) | Space: O(1)

### 4. Count Vowels
- Traverse once, check if the lowercase character is in {a, e, i, o, u}
- Convert with `tolower()` first so uppercase vowels are counted too
- Time: O(n) | Space: O(1)

### 5. Count Consonants
- Same traversal as vowels, but first check that the character is a
  letter (`isalpha()`), then that it is NOT a vowel
- Trap: spaces, digits and symbols are neither vowels nor consonants
- Time: O(n) | Space: O(1)

### 6. First Non-Repeating Character
- Pass 1: build a frequency table (`unordered_map` or `int freq[26]`)
- Pass 2: return the first character whose frequency is 1
- Two passes are needed because the first pass must finish before any
  character can be declared non-repeating
- Time: O(n) | Space: O(1) for a fixed alphabet, O(k) for k unique characters

### 7. Longest Palindromic Substring
- Expand Around Center: for every index, expand outward for both
  odd-length (i, i) and even-length (i, i+1) palindromes
- Track `start` and `maxLen`, then return `s.substr(start, maxLen)`
- 2n-1 possible centers in total
- Time: O(n²) | Space: O(1)
- Manacher's algorithm gives O(n) but is rarely expected in interviews

### 8. Reverse Words in a String
- `istringstream` extracts words and skips extra, leading and trailing spaces
- Prepend each new word to the result so the order is reversed
- Time: O(n) | Space: O(n)

---

## Key Patterns to Remember (not code!)

| Problem type | Core technique |
|---|---|
| Reverse / palindrome | Two pointers from both ends |
| Count or classify characters | Single traversal + character checks |
| First unique / duplicates | Frequency table (array or hashmap) |
| Longest palindromic substring | Expand around every center (odd + even) |
| Word-level manipulation | `istringstream` to split on whitespace |

## Common Mistakes to Avoid
- Comparing indices instead of the characters at those indices
- Returning true inside the palindrome loop instead of after it
- Forgetting even-length palindromes in Longest Palindromic Substring
- Not handling uppercase and lowercase consistently (`tolower()`)
- Counting spaces, digits or symbols as consonants
- Manually splitting words and forgetting to collapse multiple spaces

## Complexity Summary
| Problem | Time | Space |
|---|---|---|
| String Traversal | O(n) | O(1) |
| Reverse String | O(n) | O(1) |
| Valid Palindrome | O(n) | O(1) |
| Count Vowels | O(n) | O(1) |
| Count Consonants | O(n) | O(1) |
| First Non-Repeating Character | O(n) | O(1) / O(k) |
| Longest Palindromic Substring | O(n²) | O(1) |
| Reverse Words | O(n) | O(n) |

## Interview Takeaways
- Most string problems are array problems in disguise, so two pointers and
  frequency counting solve the majority of them
- Always clarify: case sensitivity, spaces and punctuation, empty string
- Know the STL helpers: `isalpha`, `isalnum`, `tolower`, `substr`, `reverse`,
  `istringstream`
- Mention in-place vs extra-space trade-offs when discussing your solution