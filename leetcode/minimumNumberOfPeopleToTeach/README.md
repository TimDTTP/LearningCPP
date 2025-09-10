
# Problem
Given...
    - int, n
    - vector\<vector\<int>>, languages
    - vector\<vector\<int>>, friendships

Return...
    - int

Where...
languages\[i] is a list of languages user i knows. Friendships\[i] depicts the
friendship of 2 people; \[ui, vi]. By only being able to teach one language, 
what is the minimum number of users do you need to teach for all the friends to 
be able to communicate with each other.

[\#1733 Minimum Number of People to Teach](https://leetcode.com/problems/minimum-number-of-people-to-teach/description/?envType=daily-question&envId=2025-09-10)

## Constraint
- 2 <= n <= 500
- languages.length == m
- 1 <= m <= 500
- 1 <= languages\[i].length <= n
- 1 <= languages\[i]\[j].length <= n
- 1 <= ui < vi <= languages.length
- 1 <= friendships.length <= 500
- All tuples \(ui, vi) are unique
- languages\[i] contains only unique values

## Approach
-

## Improvements

