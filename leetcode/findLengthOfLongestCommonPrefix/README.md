
# Problem
Given...
- Vector\<int\>, "arr1"
- Vector\<int\>, "arr2"

Return...
- Int

Where...
return is the length of the longest common prefix that exists between arr1 and
arr2. Return 0 if no commonalities.

[3043. Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24)

## Constraints
- 1 <= arr1.length, arr2.length <= 5 * 10^4
- 1 <= arr1\[i\], arr2\[2\] <= 10^8

## Approach
Approach using a tree approach
- Traverse through arr2
- For each value, traverse digits
- For each digit try to find the digits in the tree
- If it does not exist, add to vector of nodes
- This tree will be base search tree to search against
- Traverse arr1 and for each value traverse digits
- By digit, try to find value in tree
- If match, narrow down scope and increment counter
- If not a match, check if current counter is greater than max
- At the end return max counter
