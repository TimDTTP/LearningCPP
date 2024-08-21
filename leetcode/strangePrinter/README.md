
# Problem
Given...
- A string, s

Return...
- An int

Where...
The return value is the smallest possible number of turns needed to print s.
The printer can only print a sequence of the same characters at a time.
The printer can start and end the print at any index. 
A turn is the alteration to a differenct character.

[\#664 Strange Printer](https://leetcode.com/problems/strange-printer/description/?envType=daily-question&envId=2024-08-21)

## Constraints
1 <= s.length <= 100
s consists of only lowercase english letters

## Approach
- Iterate from beginning and end
- Find beginning's char from end
- Recursively solve for chars within
- Count each one
- Start from end of previous "loop"
- Repeat till end index is the end of the string
