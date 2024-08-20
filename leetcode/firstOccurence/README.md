
# Problem
Given... 
- A string, haystack
- A string, needle

Return...
- An int

Where...
The int is the index value of the first occurence of the string "needle" in the 
string "haystack"

[\#Find the index of the first occurence in a string](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

## Constraints
- 1 <= haystack.length, needle.length <= 10^4
- haystack and needle only have lowercase english letters

## Approach
- Iterate through haystack for first match
- Once matched, have one pointer on each needle and haystack
- Keep iteration and track if they match
- Whilst track if any needle[0] are repeated in the haystack and track them
- If they do not match, move the haystack's pointer to next occurence that
matches needle[0]
- Reset needle pointer
- If haystack does not already have one, start for furthest point and find next
