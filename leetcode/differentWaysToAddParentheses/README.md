
# Problem
Given...
- A string, expression

Return...
- A vector<\int>

Where...
the vector is the list of possible results from computing all the possibilities
to group the values and operators in expression

[\#241 Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19)

## Constraints
- 1 <= expression.lenght <= 20
- expression consists of digits and the operators, +, -, and *
- all integer values in expression are [\0, 99]
- all integer values do not have - or + denoting the sign

## Approach
- Iterate through string
- Combine each value to next value using operator
- Recursively call function until string is only one value, which add to output
