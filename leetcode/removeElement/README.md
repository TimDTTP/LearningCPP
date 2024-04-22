
# Problem
Given...
- A vector of integers, nums
- A integer, val

Return...
- An integer, the number of elements that are not equal to val

Which...
- The values are removed in place in the vector

[\#27 Remove element](https://leetcode.com/problems/remove-element/description/)

## Constraints
- 0 <= nums.length <= 100
- 0 <= nums[i] <= 50
- 0 <= val <= 100

## Approach
- 2 pointer
1. One pointer starts that the beginning
2. One pointer starts from the end
3. Traverse end pointer until it isn't equal to val
4. Traverse beginning pointer until it meets val
5. Continue if beginning pointer is still < end pointer
6. If beginning pointer == val, swap beginning and end pointer
7. Return beginning pointer index at the end
