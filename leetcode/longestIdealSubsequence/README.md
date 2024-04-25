
# Problem
Given...
- A string, 's'
- A integer, 'k'

Return...
- A integer

Which is the length of the longest "ideal substring". The ideal substring is a 
string which the difference of adjacent letters in alphabetical order is less 
than or equal to 'k'.

[\#2370 Longest ideal subsequence](https://leetcode.com/problems/longest-ideal-subsequence/description/)

## Constraints
- 's' consists of lowercase english letters
- Alphabet order is NOT cyclic
- 0 <= k <= 25
- 1 <= s.length <= 10^5

## Approach
1. Iterate through string (i < s.length() - 2)
2. If ((index + 1) - index) <= k 
    then ++counter
3. Else compare current largest length
4. Reset 'counter'
Time comp: O(n)
