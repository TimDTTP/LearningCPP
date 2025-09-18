
# Problem
Given...
    - A vector\<vector\<int>>, tasks

Return...
    -  An int 

Where...
the class is composed of 5 functions.
- TaskManager\(vector\<vector\<int>> tasks)
    - Initialize task manager with given user-task-priority triplets
- void add\(int userId, int taskId, int priority)
    - Adds task with the specified user and priority level
- void edit\(int taskId, int newPriority)
    - Update the priority level of the specified task
- void rmv\(int taskId)
    - Remove the task
- int execTop\()
    - Executes the task with the highest priority; if same priority exec higher 
    taskId
    - Remove taskId
    - Return the userId associated with the task
    - If no tasks are available, return -1

Note: a user may be assigned multiple tasks

[\#3408 Design Task Manager](https://leetcode.com/problems/design-task-manager/description/?envType=daily-question&envId=2025-09-18)

## Constraint
- 1 <= tasks.length <= 10^5
- 0 <= userId <= 10^5
- 0 <= taskId <= 10^5
- 0 <= priority <= 10^9
- 0 <= newPriority <= 10^9
- At most 2 * 10^5 calls will be made
- The input is generated such that taskId will be valid

## Approach
- Organize into a map\<taskId, customType>
    - customType
        - int user
        - int priority
- For execTop
    - Sort the map by priority than taskId
    - Hold userId
    - Run rmv to top id
    - Return userId

## Improvements

