
# Problem
Given...
- The head of a singly linked list, 'head'

Return...
- The head of the new linked list

Which no node to the right of it is greater that itself.

[\#2487 Remove nodes from linked list](https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-05-06)

## Constraints
- 1 <= val <= 10^5
- 1 <= number of nodes <= 10^5

## Approach
1. Iterate through linked list
2. Add value and "index" to ordered map
3. Sort map by value
4. Iterate through map and add to new linked list
    - If index is greater than current + add to linked list
5. Return new linked list
