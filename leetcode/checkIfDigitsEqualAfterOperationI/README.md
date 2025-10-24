
# Problem
Given...
    - String, s

Return...
    - Bool

Where...
After performing the following operation until there is only 2 digits left, 
return if the two digits are the same. 

The operation is adding 2 consecutive digits and reducing it to modulo 10. 
Maintain the order in which they are computed.

[\#3461 Check If Digits Are Equal In String After Operations I](https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23)

## Constraint
- 3 <= s.length <= 100
- s consists of only digits
## Approach
- Total number of iterations is s.size - 2
- Each iteration's length is s.size - currentIteration
- Using these variables, we can insert and check values at constant time
- Loop through and perform operations and push back onto same string
- Return if last 2 values are equivalent

Runtime
0ms beats 100%
Memory
8.78mB beats 81.62%

## Improvements
No noticeable large difference in improvement
