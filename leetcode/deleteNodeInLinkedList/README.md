
# Problem
Given...
- A node in a linked list, 'node'

Return...
- Void

Which we remove 'node' from the linked list.

## Constraints
- List head is not given
- 'node' is NOT last
- number of node [2, 1000]
- -1000 <= node.val <= 1000
- Each value is unique

## Approach
1. Replace current node with next's value
2. Continue until next's next is NULL, then assign next to NULL
    - AKA until 2nd to last node

## Submission
Time 3ms Beats 92.47%
Memory 11.45MB Beats 5.44%

## Online Solution
Little to no significant improvements
