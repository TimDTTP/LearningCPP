
# Problem

Question #1 from LearnCPP Chapter 11.11

Write a program that:

- Asks the user how many names they wish to enter.
- Dynamically allocates a std::string array.
- Asks the user to enter each name.
- Calls std::sort to sort the names (See 11.4 -- Sorting an array using - selection sort and 11.8 -- Pointer arithmetic and array indexing)
- Prints the sorted list of names.

std::string supports comparing strings via the comparison operators < and >. You don’t need to implement string comparison by hand.

Your output should match this:
How many names would you like to enter? 5
Enter name #1: Jason
Enter name #2: Mark
Enter name #3: Alex
Enter name #4: Chris
Enter name #5: John

Here is your sorted list:
Name #1: Alex
Name #2: Chris
Name #3: Jason
Name #4: John
Name #5: Mark