
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
- Form a struct to enable easier manipulation
    - letter
    - pair<double, single>
- Add number of occurences to singles for each letter
- Add structs to array and sort
- Iterate through and add the largest value that is NOT the last one added
- If number of moves = 0, remove
