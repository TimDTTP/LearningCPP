
# Problem
Given...
    - String, s

Return...
    - Integer

Where...
Given a binary string, s, where 1 represent an active section, 0 represent 
an inactive. By performing one trade in which...
- On congious block of 1's are converted to 0's
- That same block is then converted to  all 1's
- Return the maximum number of active sections in s

[#3499 Maximize active section with trade I](https://leetcode.com/problems/maximize-active-section-with-trade-i/description/?envType=daily-question&envId=2026-07-21)

## Constraint
- 1 <= n == s.length == 10^5
- s\[i] is either '0' or '1'

## Approach
- Traverse and count length of each substring and add to vector
- For each index the represent 1 accumulate s\[i], s\[i + ..4]
    - 4 positions or until end
- Accumulate 1 time for the front
- Return max

Runtime:
83ms beats 65.65%
Memory:
104.89mb beats 33.27%

## Improvements

