
# Problem
Given...
    - TreeNode*, root

Return...
    - TreeNode*

Where...
The return tree is a balanced binary search tree.
Balanced means that the 2 subtree's depth of each node never differ more than 1

[#1382 Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09)

## Constraint
- The number of nodes in the tree is in the range \[1,10^4] 
- 1 <= Node.val <= 10^5
- Root is a binary search tree

## Approach
- Convert binary tree into a vector via DFS in-order
- Find middle point of vector and branch out adding continually to binary 
tree

## Improvements


