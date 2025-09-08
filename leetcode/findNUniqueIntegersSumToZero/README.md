
# Problem
Given...
    - int, n

Return...
    - vector\<int>

Where...
the return vector is an array containing n unique integers that add up to 0

[\#1304 Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?envType=daily-question&envId=2025-09-07)

## Constraint
- 1 <= n <= 1000

## Approach
- Cover edge case, n == 1
- Iterate from 1 up to n \(not including)
- Add value to vector
- Last value add negative summation of all values added thus far
    - AKA; -\(\(n - 1) * \(\(n - 1) + 1) / 2)

Runtime:
0ms beats 100%
Memory:
9.74mB beats 13.84%

## Improvements
Same logic path with minimal optimizations AKA; equation simplifiying
