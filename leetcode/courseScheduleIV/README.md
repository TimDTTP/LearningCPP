
# Problem
Given...
- A integer, numCourses
- A vector of vectors of integers, prerequisites
- A vector of vectors of integers, queries

Return...
- A vector of bools

Where...
numCourses represent the number of available courses that are available and 
prerequisites represent the relationship of courses where the first value is the
required course to take the second. Return a vector that responds to the query 
of if course\[0] is a prerequisites of course\[1].

[#1462 Course Schedule IV](https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27)

## Constraints
- 2 <= numCourses <= 100
- 0 <= prerequisites.length <= \(numCourses * (numCourses - 1) / 2) 
- prerequisites\[i].length == 2
- 0 <= a, b <= numCourses - 1
- a != b
- All the pairs \[a, b] are unique
- The prerequisites graph has no cycles
- 1 <= queries.length <= 10^4
- 0 <= u, v <= numCourses - 1
- u != v

Translation
- No need to...
    - bound check size of prerequisites\[i]
    - bound check value of prerequisites\[i]
    - check course being a prerequisites of itself
    - check duplicate prerequisites
    - infinite cycle of prerequisites
    - bound check size of queries\[i]
    - bound check value of queries\[i]
    - check comparisons of course with itself

## Approach
Note: knowledge gap. Suspecting problem requires thorough knowledge of graph 
data structure, which is a personal weakpoint, for now...

