
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
Note: Needs to check if indexing letter will fall out of index
A solution is to sort smallest to largest word.

- Queues
1. Initialized a queue for each word
2. Compare de-queue
3. If not all equal, return

- Process of elimination
1. Take first word as benchmark
2. Iterate through list of words
3. For each letter that does not match, remove from benchmark
4. Will narrow down until it fits desired result

## Online Solutions
Online solution yielded similar to some approaches. 
Overall, not much more performant nor insightful to change.
