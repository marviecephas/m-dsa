# Arrays & String Manipulation

This repository contains my documentation and project implementations (C++ and Python) focusing on array mechanics, memory layout, and string manipulation algorithms.

## Arrays & Memory Fundamentals

An array is a sequence of data contiguously stored in memory. The size of an array must be known at compile time and does not allow for dynamic resizing (unlike Vectors, which also store contiguous data but can resize).

**Memory Allocation by Type:**
* `char`: 1 byte
* `bool`: 1 byte
* `int`: 4 bytes
* `float`: 4 bytes
* `long`: 8 bytes
* `double`: 8 bytes

**Strings and Characters:**
* All characters are mapped to integer values defined by ASCII (American Standard Code for Information Interchange).
* A string is mathematically treated as an array of characters terminating with a null character (`\0`). Without this null terminator, the system will continue reading contiguous memory until it arbitrarily hits a `\0`.
* A `char*` (C-type string) stores the memory address of the first letter of the string. An array of `char*` stores multiple starting addresses, essentially creating an array of strings.

---

## Project 1: Scrabble
**Objective:** Compute and compare the Scrabble score of two strings.

**Implementation Details:**
* Each character (A-Z) is mapped to a specific point value.
* Because each character has a unique ASCII integer value, the index of the character's point value in the `points` array is calculated using ASCII arithmetic: `CHARACTER - 'A'`.
* **Validation:** Characters are validated as letters (`CHARACTER >= 'A'` and `CHARACTER <= 'Z'`) before computation.
* The highest point total wins. A tie is declared if points are equal.

---

## Project 2: Readability
**Objective:** Calculate the Coleman-Liau index to determine the reading grade level of a given text.

**The Formula:**
The index is calculated using double precision:
`index = 0.058 * L - 0.296 * S - 15.8`
Where:
* **L** = average number of letters per 100 words.
* **S** = average number of sentences per 100 words.

**Implementation & Edge Case Handling:**
* **Letters:** Counted by validating alphabetic characters.
* **Sentences:** Counted by detecting punctuation (`.`, `!`, `?`).
* **Words (State Machine Logic):** Simply counting spaces is inaccurate (e.g., double spaces, trailing spaces). This was solved by implementing a boolean flag `in_word`. The flag is set to `true` when encountering a valid character and `false` when hitting a space or sentence-ending punctuation. Words are only incremented when transitioning out of a word.
* **Output:** The final grade is the rounded integer of the index. Values `<1` output "Before Grade 1", and values `>16` output "Grade 16+".

---

## Project 3: Caesar
**Objective:** Encrypt plaintext into ciphertext using a numerical key to shift characters by a specific offset.

**Implementation Details:**
* **Key Validation:** The command-line argument is validated to ensure it contains only positive integers (`k >= '0'` and `k <= '9'`).
* **String-to-Integer Conversion:** The string key is manually converted to an integer by iterating through the characters, multiplying by powers of 10, and summing the results.
* **Shift Logic:** The alphabet contains 26 letters (0-25). To shift correctly without hitting invalid ASCII ranges, the base ASCII value (`'A'` or `'a'`) is subtracted to normalize the letter to a 0-25 scale. The key is added, modulo 26 is applied to wrap around the alphabet, and the base ASCII value is added back.
* **Core C++ Logic:**
    ```cpp
    ciphertext += (c >= 'A' and c <= 'Z') ? ('A' + (c - 'A' + k) % 26) : ((c >= 'a' and c <= 'z') ? ('a' + (c - 'a' + k) % 26) : c);
    ```

---

## Project 4: Substitution
**Objective:** Encrypt plaintext using a unique 26-letter key mapping, preserving case sensitivity.

**Implementation Details:**
* **Key Validation:** The key must be exactly 26 unique alphabetical characters. A boolean array (`has_occurred`) tracks the presence of each letter to guarantee no duplicates. The length is tracked simultaneously to ensure exactly 26 letters are provided with no invalid ASCII characters.
* **Encryption Logic:** The character in the plaintext is used to find its alphabetical index (0-25). That index is used to pull the corresponding character from the provided key.
* **Case Handling:** The substitution key is case-insensitive, but the resulting ciphertext must match the case of the original plaintext.
* **Core C++ Logic:**
    ```cpp
    ciphertext += (c >= 'A' and c <= 'Z') ? key[c - 'A'] : ((c >= 'a' and c <= 'z') ? key[c - 'a'] : c);
    ```

*Credit:* Concepts and initial problem sets inspired by Harvard’s CS50x. All code here is my own implementation/notes written while working through the material.
