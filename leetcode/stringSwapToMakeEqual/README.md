
# Problem
Given...
- A string, s1
- A string, s2

Return...
- A bool

Where...
it is possible to perform at most one string swap on exactly one string to make
both s1 and s2 equal to each other.
- A string swap is an operation where you can choose 2 indices of a string to
swap the characters

[#1790 Check if one string swap can make strings equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05)

## Constraints
- 1 <= s1.length, s2.length <= 100
- s1.length == s2.length
- s1 and s2 consist of only lowercase English letters

## Approach
- Include a edge case if both s1 and s2 are the same initially
- Iterate through s2 and find the first 2 inconsistencies
- Afterwards terminate loop and swap the characters of both indices
- Check if s1 and s2 are equal

Note: 
- No need to check bounds of iteration and adjacent string b/c of constraints
- No need to check if only one match is found cause only one match cannot be
swapped, leading to unequal strings

## Analysis
Time complexity: O\(n) because we are iterating through the string with 
possibility that we have to iterate through entire string.

Space complexity: O\(1) only dedicated space is to store a index and temp
value.

Runtime:
0ms Beats 100%

Memory: 
8.38mB Beats 61.87%

