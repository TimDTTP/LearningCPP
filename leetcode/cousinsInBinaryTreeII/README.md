
# Problem 
Given...
- A tree node, root

Return...
- A tree node

Where...
the return node is the root of the modified tree. Replace the value of each node
in the tree with the sum of all of it's cousins' values

Nodes are cousins if they have the same depth with different parents.

[#2641 Cousins in Binary Tree II](https://leetcode.com/problems/cousins-in-binary-tree-ii/description/?envType=daily-question&envId=2024-10-23)

## Constraints
- Number of nodes in tree in range \[1, 10^5]
- 1 <= Node.val <= 10^4

## Approach
- Add root to queue
- For size queue, pop and push back into queue
    - Whilst add node.children.left && right to temp sum
- For size queue, pop and push back into queue
    - Whilst assign child of each node 
        - val = sum - node.left->val - node.right->val
    - Add node.left && node.right to end
- Return root

