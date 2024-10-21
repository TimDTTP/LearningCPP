
# Problem
Given...
- A string, s

Return...
- An int

Where...
the return value is the max number of unique substrings that can be created from
's'.

[#1593 Split a String Into The Max Number of Unique Substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21)

## Constraints
- 1 <= s.length <= 16
- 's' only contain lower case English letters

## Approach
Map method
- Iterate through string by char
- If char is not in map
    - counter++
- If char is already in map
    - Add next char and recheck
    - Repeat until satisfied
- Return counter

Problem: Doesn't optimize max amount

Try every permutation tracking using set
- Iterate through length of string
- Test every combination 
- Track max amount
- Recursive call back to function with new limits
- Dump set at end of loop
