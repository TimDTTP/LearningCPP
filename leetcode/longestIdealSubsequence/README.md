
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
1. Iterate through string
2. If index + 1 - index > k
3. Recursively call function from 'new' starting point
4. Compare + return max amount
5. If index + 1 - index <= k
6. ++counter
7. Finally return max

