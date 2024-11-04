
# Problem
Given...
- A string, "word"

Return...
- A string

Where...
the return string is the compressed version of "word" using the following 
algorithm.
- Remove the prefix of "word" made of a single character 'c' repeating at most 9
time.
- Append the length of the prefix followed by 'c'

[#3163 String Compression III](https://leetcode.com/problems/string-compression-iii/description/?envType=daily-question&envId=2024-11-04)

## Constraints
- 1 <= word.length <= 2 * 10^5
- "word" consists of only lowercase English letters.

## Approach
Two pointer
- Both pointer start at index 0
- Traverse second pointer to next index
- If char == char under first pointer, keep going and counter++
- Else or end
    - Append counter then char
    - Shift first pointer to second pointer
- Return comp

Runtime 36ms Beats 57.27%
Memory 39.98mB Beats 6.10%
