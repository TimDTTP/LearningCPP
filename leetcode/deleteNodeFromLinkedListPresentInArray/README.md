
# Problem
Given...
- vector<\int>, nums
- ListNode*, head

Return...
- ListNode*

Where...
The return is the head of the new linked list with all the values in nums
removed from head

[\#3217 Delete Nodes From Linked List Not Present In Array](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-07)

## Constraints
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^5
- All elements in nums are unique
- Number of nodes ranges [1, 10^5]
- 1 <= node.val <= 10^5
- There is at least one value in head that is not present in nums

## Approach
- Migrate nums into set for faster lookup
- Use 2 pointer method
- First pointer is verified not in nums
- Second pointer tests if next node.val is in nums
- If not
    - First pointer = second pointer
    - second pointer = pointer.next
- If yes
    - Second pointer = pointer.next
    - First pointer.next = second pointer
- Repeat until second pointer = nullptr
