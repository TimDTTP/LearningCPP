
# Problem
Given...
- a binary tree root node
- an integer value
- an integer depth

Return...
- a binary tree root node

Which is the new tree where the nodes at 'depth' depth, is replaced with 'value'.

[\#623 Add One Row to Tree](https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16)

## Constraint
- -100 <= node.val <= 100
- -10^5 <= val <= 10^5 

## Approach
- Recursive
1. Iterate 'depth' value down
2. Hold onto original branches address
3. Point to new 'value'
4. Value's left/right point to original respective to whether its is left/right
