
# Problem
Given...
- A string, 's'

Return...
- An integer

Where...
the return value is the minimum number of changes to partition the string
such that it is considered "beautiful".
Requirements to be beautiful...
- Each substring has an even length
- Each substring can contain either all '1' or all '0'

[#2914 Minimum Number of Changes to Make Binary String Beautiful](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/)

## Constraints
- 2 <= s.length <= 10^5
- 's' has an even length
- s\[i] is either '0' or '1'

## Approach
- There is a limited amount of options for patterns of odds and evens
- Thus, with constraints in mind, we can just account for the order of odds and evens
- Traverse through string, and account of if substrings are odd or even amount
- Add odd or even in a queue
- Traverse queue
- If odd, evaluate the next in queue
    - If odd, add 1 to counter
    - If even, count how many even till we reach odd
        - Add number of even till odd +1 to counter

Runtime 3ms Beats 43.24%
Memory 14.36mB Beats 17.58%
