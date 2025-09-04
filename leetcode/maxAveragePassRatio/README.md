
# Problem
Given...
    - A vector\<vector\<int>>, classes
    - A int, extraStudents

Return...
    - A double

Where...
    - The return value is the maximum possible average pass ratio after 
assigning the "extraStudents".
    - classes\[i] = \[pass, total]
        - \[Total number of passing grades, total number of students in class i]
    - extraStudents are guaranteed to pass the exam of any class they are 
assigned to
    - Pass ratio = \# of passing grades \/ number of students in class i
    - Average pass ratio = sum of pass ratios \/ number of classes

[\#1792 Maximum Average Pass Ratio](https://leetcode.com/problems/maximum-average-pass-ratio/description/)

## Constraint
- 1 <= classes.length <= 10^5
- classes\[i].length == 2
- 1 <= pass <= total <= 10^5
- 1 <= extraStudents <= 10^5

## Approach
- Distill classes into a vector\<pair\<int, double>> where int is the index
and double is the pass ratio \+ extraStudent, \(plus 1 to both values), minus 
the current pass ratio
    - This is the difference of how 1 extra passing student can make on the 
    class average
- Sort the vector by the pass ratio, non-decreasing order
- For each extraStudents, take the largest difference from diff and increment
pass and total, and update the difference by incementing another time and
re-inserting into the vector
- Sort the vector again 
- By the end, take all the classes pass ratio and return the average

Note: Approach passed time limit testcase \#44

Re-approach:
Simplify formula and find a simpler pattern rather than "brute forcing" it

## Improvements
Failed! TLE

We could've use a max heap as a priority queue to reduce an extra iteration 
which is used to get the potential pass ratio if an extra student was added
