
# Problem
Given...
- vector<\int>, rolls
- int, mean
- int, n

Return...
- vector<\int>

Where...
n is the number of missing observations. Return ONE possibility of values, in
an vector of values that could be missing. The values must be values 1-6 (on a
dice), and final observations must have an average of mean.

[\#2028 Find Number of Observations](https://leetcode.com/problems/find-missing-observations/description/?envType=daily-question&envId=2024-09-05)

## Constraints
- m == rolls.length
- 1 <= n, m <= 10^5
- 1 <= rolls[\i], mean <= 6

## Approach
- Base cases
    - Sum missing > (6 * n)
        - Return {};
    - Sum missing < (1 * n)
        - Return {};
- Divisor = rolls.size + n
- Sum missing = means * divisor - sum(rolls)
- Find a set of values of length "divisor", which totals to "sum missing"
- To get possible numbers:
    - Divide sum missing by n, this is to get baseline
    - For (sum missing - n * baseline)
        - Iterate through vector and add 1


