
# Problem
Given... 
- int, a
- int, b
- int, c

Return...
- A string

Where...
the return value is the longest string that is considered "happy". A string is
happy if...
- Does not contain "aaa", "bbb", or "ccc"
- Only contains 'a', 'b', or 'c'
- 'a' can only occur a amount of times
- 'b' can only occur b amount of times
- 'c' can only occur c amount of times
Return "" if there are no happy substrings.

[#1405 Longest Happy String](https://leetcode.com/problems/longest-happy-string/description/)

## Constraints
- 0 <= a, b, c <= 100
- a + b + c > 0

## Approach
- Group a, b, c into pairs which simplifies the numbers
- pair.first is a / 2
- pair.second is a % 2
- Number of possible move = pair.first + pair.second
- Sort by number of possibles moves
- If delta between each is 1 or 0
    - Just iterate through each (easy)
- Else,
    - Group 2 lowest occurences together and get number of moves closest to the
    greatest
    - When forming string, alternate between the two lowest values between
    the greatest values

