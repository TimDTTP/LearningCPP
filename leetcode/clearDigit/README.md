
# Problem
Given...
- A string, s

Return...
- A string

Where...
the return string is after removing all digits and the closest non-digit 
character to its left

[#3174 Clear digits](https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10)

## Constraints
- 1 <= s.length <= 100
- s consists only of lowercase English letters and digits
- Able to be delete all digits in input

## Approach
- Iterate through string via index
- If the char is a number, delete that number + whatever position is infront 
of it unless the index is already 0
- Return string

## Result
Time complexity:
O\(n) because this is a one pass solution including only a single for loop.

Space complexity:
O\(1) because there is no dedicated memory that is required that is scaled to
the size of the input. To further prove, there is also zero initialized or 
defined variables in the approach.

Runtime: 0ms Beats 100%
Memory: 8.36mB Beats 87.07%

