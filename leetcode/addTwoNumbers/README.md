
# Problem
Given...
1. 2 Linked lists

Return...
1. 1 Linked list

Which the value of the given linked list will only contain a single digit of the integer stored in reverse order. Return the sum of the 2 integers also in reverse order.

[\#2 Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)

## Constraints
- Node.val is guaranteed to be a value 0 to 9
- Linked list guaranteed to be a number with no leading zeros

## Approach
- Brute force
1. Traverse both each list and obtain each value, each time num * 10^i + original
2. Add both numbers
3. Push value into linked list
    sum % 10; 
    sum / 10; (with data loss) 
4. Return new linked list

- 2 Pointer
1. Each pointer point at the head of each list
2. Traverse each list and add values
3. If sum > 10, flip flag from next value and add +1
4. Run until either list == NULL
5. At the end if one list != NULL, append remaining to end of list (add 1 if flag is still flipped)
Time complexity O(n)
Space complexity O(1)


