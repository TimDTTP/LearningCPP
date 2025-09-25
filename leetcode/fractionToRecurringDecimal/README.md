
# Problem
Given...
    - int, numerator
    - int, denominator

Return...
    - string

Where...
Return the fraction in string format \(decimal value)
- If the fractional part is repeating, enclose repeating part in parentheses

[\#166 Fraction to Recurring Decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/description/?envType=daily-question&envId=2025-09-24)

## Constraint
- -2^31 <= numerator, denominator <= 2^31 - 1
- denominator != 0

## Approach
- Reduce fraction using Euclid algo
- Factor out 2's and 5's from denominator
    - \{2^x, 5^y}
    - init \{x, y, remaining}
- bool terminate = remaining == 0
- Determine cycle length
    - Find k
        - 10^k % remaining == 1
- Determine non-repeat length == max\(x, y)
Note: problem of cpp not handling decimal digits past 16 floating points
- Simulate long division up to non-repeat length + cycle length
    - Add first non-repeat length after decimal
    - If terminate, add '\('
    - Add rest of value
    - If terminate, add '\)'


## Improvements

