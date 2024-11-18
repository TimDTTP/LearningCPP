
# Problem
Given...
- A vector of integers, "code"
- A integer, 'k'

Return...
- A vector of integers

Where...
the return value is where code\[i] = sum\(i+1, i+2, i+3)
the sum of the next/previous 'k' values, this is used circularly
- If k = 0, all values are replaced with 0

[#1652 Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/description/)

## Constraints
- n == code.length
- 1 <= n <= 100
- 1 <= code\[i] <= 100
- -\(n - 1) <= k <= n - 1

## Approach
Two pointer
- Ptr1 +1 direction going
- Ptr2 +k direction going
- Sum = sum of next k int
- Iterate through array
- Replace value with sum
- Sum - ptr1
- Increment both ptrs
- Sum + ptr2
- return array

Runtime 0ms Beats 100.00%
Memory 10.29mB Beats 84.00%
