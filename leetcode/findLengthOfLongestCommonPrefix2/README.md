
# Problem
Given...
    - Vector\<int> arr1
    - Vector\<int> arr2

Return...
    - Integer

Where...
arr1 and arr2 are arrays with only positive integers. Return the length of the 
longest common prefix between 2 values, one in each vector parameter.

[#3043 Find the length of the longest common prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2026-05-21)

## Constraint
- 1 <= arr1.length, arr2.length <= 5 * 10^4
- 1 <= arr\[i], arr2\[i] <= 10^8

## Approach
- Turn arr2 into a tree where first value is the root
- Iterate through arr1 and find longest prefix 
- Return max

Runtime:
459ms beats 10.33%
Memory:
430.02mB beats 5.08%

## Improvements
- On the right track but there exist a Trie that perform this prefix form
of tree
