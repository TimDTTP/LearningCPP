
# Problem
Given...
    - vector\<string>, words

Return...
    - vector\<string>

Where...
In an operation if any index of words, in which words\[i] and words\[i - 1] are
anagrams, delete words\[i]. This operation can be performed as many times as
possible. Return words after performing all operations.
Note: performing this in any order will yield the same result
- An anagram is any word whose letters can be re-arranged to produce another

[\#2273 Find Resultant Array After Removing Anagrams](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/?envType=daily-question&envId=2025-10-13)

## Constraint
- 1 <= words.length <= 100
- 1 <= words\[i].length <= 10
- words\[i] consists of lowercase English letters

## Approach
- Compile each word in words into a map\<char, int> where you count number of
each character
- Push each map into a vector in place of words
- Loop through
    - if i + 1 is the same as i
        - erase i + 1
        - decrement i
        - decrement size

Runtime:
37ms beats 5.06%
Memory:
27.16mB beats 5.78%

## Improvements
- If working with an element with a hard cap on possible values, consider
a vector with a set size \(ie. letters, max 26 possibilities)
- Another way to check congruency in this situation is to increment index
of the letter for one word and decrement with the other. Check if all zero
