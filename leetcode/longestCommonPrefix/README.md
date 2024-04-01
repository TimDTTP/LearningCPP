
# Problem
Given an array of strings...
return the longest common prefix

[\#14 Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/)

## Note
Vector "only consists of lowercase English letters"

## Approaches
- Brute force (nested loop)
1. Take the first letter of the first word
2. Cross check across all words in array
3. Increment letter

- Queues
1. Initialized a queue for each word
2. Compare de-queue
3. If not all equal, return
