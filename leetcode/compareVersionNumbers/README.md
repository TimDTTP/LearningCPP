
# Problem
Given...
- A string, string1
- A string, string2

Return...
- An integer

Where if 
'string2' is greater, return -1
'string1' is greater, return 1
else, return 0

[\#165 Compare version numbers](https://leetcode.com/problems/compare-version-numbers/description/)

## Constraints
- 1 <= length <= 500
- strings are valid version numbers
- strings only contain digits and '.'
- all values can be stored in 32-bit int

## Approach
1. Iterate through each string tracking the sum until decimal or end of str
    sum = sum * 10 + string[i]
2. Return corresponding value based on comparison
3. At the end return 0 since they are the same

## Online solution
Minimal to no significant improvements
