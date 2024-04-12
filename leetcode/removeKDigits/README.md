
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
1. If k == num.length return 0
2. Get number of non-zero values in string
3. If k > number of non-zeroes, return 0
4. Traverse list, if next number is less than current, remove current
5. Remove only k digits
