
# Problem
Given...
- A string, s

Return...
- A string

Where...
the return value is string "s", which is considered "fancy"; deleting the
minimum possible number of characters as possible.
A string is fancy is there does not exists a character that appears more than
twice consecutively.

[#1957 Delete Characters to Make Fancy String](https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/)

## Constraints
- 1 <= s.length <= 10^5
- s consists only of lowercase English letters

## Approach
- Track char and consecutive frequency
- Set char as first character and freq 1
- Start traversing starting from index 1
- If it matches char, increase frequency
    - If freq >= 3
        - Delete char under index
        - Decrease index by 1
- Else, change char to current and freq to 1
- Return string
