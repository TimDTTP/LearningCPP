
# Problem
Given...
- A node, root

Return...
- A vector

Where...
the return vector is a series of int values in postorder, using the root node.

[\#590 N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26)

## Constraints
- Number of nodes [0, 10^4]
- 0 <= node.val <= 10^4
- Height of tree <= 1000

## Approach
- For each node, starting from root iterate over children nodes
- Each parent add value to vector from end
- Repeat recursively with child node instead of parent

## Online solution
- Reduced clutter using std::function
- lambda function allows 1 less std::vector initialization
