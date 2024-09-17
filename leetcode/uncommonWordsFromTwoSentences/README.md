
# Problem
Given...
- A string, s1
- A string, s2

Return...
- A vector<\string>

Where...
The return is a vector of uncommon words between both s1 and s2.
An uncommon word is a letter that appears only once in both sentences.

[\#884 Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17)

## Constraints
- 1 <= s1.length, s2.length <= 200
- s1, s2 only contain lowercase English letters and spaces
- s1, s2 do no have any leading or trailing spaces
- All words in s1, s2 are separated by a single space

## Approach
- Combine to one string
- Iterate through and add to a map "string : occurence"
- If occurence > 1, not uncommon
