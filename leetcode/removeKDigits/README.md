
# Problem
Given...
1. String num
2. Int k
Return...
1. String num

Return the smallest possible value after removing 'k' digits from num.

[\#402 Remove K Digits](https://leetcode.com/problems/remove-k-digits/description/?envType=daily-question&envId=2024-04-11)

## Constraint
- 1 <= k <= num.length <= 10^5
(will fit into int)
(does not need to check if string is empty)
- num consists of only digits
(no need to check)
- num does not have any leading zeros (except 0 itself)

## Approach
- Stack
1. Iterate through string
2. Push num into stack
3. If num < stack.top(), pop until num > stack.top()
4. Continue until k == 0
5. If k != 0 and we are at the end, stack.pop() last numbers (they are the largest)
6. Get rid of leading 0s and return
