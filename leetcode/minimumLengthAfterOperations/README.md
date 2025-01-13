
# Problem
Given...
- A string, s

Return...
- A integer

Where...
the return value is the minimum length that you can reduce s down to. You can 
only reduce s by choosing an index i that has at least one character that is 
equal to s\[i] on both left and right. Then delete both characters on each side

This can be repeated any number of times.

[#3223 Minimum Length of String After Operations](https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13)

## Constraints
- 1 <= s.length <= 2 * 10^5
- s consists only of lowercase English letters

## Approach
From an analysis, it seems that the order of the characters can be disregarded.
The only required information is the character and the frequency. 
- Iterate through string
- Track characters appearance through a dictionary and a bool
- If new char, increment count
- If current char appears and odd amount of times, that is reduced to 1
- If current char appears and even amount of time, that is equivalent to 2

Runtime 126ms Beats 15.32%
Memory 32.50mB Beats 36.69%

Optimizations
- Since there is only 26 possible characters, use an array instead of a map
- Test whether calculating at the end or during will be faster

Runtime 4ms Beats 98.39%
Memory 32.27mB Beats 52.42%
