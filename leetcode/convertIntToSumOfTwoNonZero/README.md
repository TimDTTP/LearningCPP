
# Problem
Given...
    - int, n

Return...
    - vector\<int>

Where...
- return is in the format \{a, b}.
- a + b = n
- a and b have no zero digit

[\#1317 Convert Integer to the Sum of Two No-Zero Integers](https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08)

## Constraint
- 2 <= n <= 10^4

## Approach
- Loop from 2 to n
- Check if value and \(n - value) have zeros
- If not, return \{value, n - value}

## Improvements

