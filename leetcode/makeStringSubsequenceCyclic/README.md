
# Problem
Given...
- A string, str1
- A string, str2

Return...
- A bool

Where...
you can select any number of indices on `str1\[i]` and increment to the next
character cyclically, that 'z' will become 'a'. It is only possible to perform
the increment once. Return if it is possible to make `str2` a subsequence of 
`str1`.

[#2825 Make String a Subsequence Using Cyclic Increments](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/)

## Constraints
- 1 <= str1.length <= 10^5
- 1 <= str2.length <= 10^5
- str1 and str2 consist of only lowercase English letters

## Approach
- Instantiate a third string, incremented `str1`
- Increment through `str2`, if `str2\[i]` is in `str1` or `str2`
    - Increment `str2`
    - If `str2` is out of bounds, return true
- Increment `str1` and `str2`
    - If `str1` is out of bounds, return false

Runtime: 2ms Beats 72.38%
Memory: 18.43mB Beats 7.53%

## Online Solution
- No need to instantiate third string for incremented string. Better to 
manipulate character's unicode values to compare distance and match.
