
# Problem
Given...
- A vector, 'people'
- An integer, 'limit'

Return...
- An integer

Which is the minimum number of boats needed to carry every given person. Each
value in 'people' represents their weight. The boat can carry at most 2 people,
and the combined weight cannot surpass the 'limit'.

[\#881 Boats to save people](https://leetcode.com/problems/boats-to-save-people/description/)

## Constraints
- 1 <= people.length <= 5 * 10^4
- 1 <= people[i] <= limit <= 3 * 10^4

## Approach
- Sort array
- Two pointers, at beginning and end
- If both pointers add and is less than limit
    - Increment boat #
    - Increment beginning pointer
    - Decrement end pointer
- Repeat until >= 1 left
- If pointer are at the same one add 1 and return
