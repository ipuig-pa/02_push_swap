# Push_swap


https://github.com/user-attachments/assets/7570157f-2f79-428d-bd9b-324492ce7cc4


This project was developed individually by:

- @ipuig-pa

## Project Overview

---

This project involves sorting a random amount of numbers on a stack with a limited set of instructions, aiming to use the lowest possible number of actions and supporting on another, initially empty, stack.  

### Resources

- https://github.com/o-reo/push_swap_visualizer : the visualization of the own push swap sorting algorithm was possible using push_swap_visualizer, by @o-reo.

## Sorting

---

### Compilation

- Use `make` to compile the project.

### Running

- Run the program with the list of integers to be sorted as an argument:

`./push_swap [list of int (stack a)]` .

### Stack Operations: output

The project outputs the operations to sort the list of numbers given as argument. It operates with two stacks (a and b) and the following allowed operations:

- `sa`: Swap the first 2 elements at the top of stack a
- `sb`: Swap the first 2 elements at the top of stack b
- `ss`: `sa` and `sb` at the same time
- `pa`: Push the top element from stack b to stack a
- `pb`: Push the top element from stack a to stack b
- `ra`: Rotate stack a (shift up all elements by 1, first element becomes last)
- `rb`: Rotate stack b (shift up all elements by 1, first element becomes last)
- `rr`: `ra` and `rb` at the same time
- `rra`: Reverse rotate stack a (shift down all elements by 1, last element becomes first)
- `rrb`: Reverse rotate stack b (shift down all elements by 1, last element becomes first)
- `rrr`: `rra` and `rrb` at the same time

### **Error handling**

Displays "Error" for non-integer arguments, arguments exceeding integer limits, or duplicate values.

## Features / Algorithm implementation

---

- Analyzing the input to determine the most efficient approach: small size, middle size and large size sort:
    - Reordering “stack a” for small size lists  (≤3 elements):
    - Supporting on “stack b”  for medium size lists  (≤10 elements):
    - K-sort algorithm implementation for large size lists  (>10 elements):
        - Sorts 100 random numbers in fewer than 700 operations
        - Sorts 500 random numbers in fewer than 5500 operations

## License

---

This project was developed as part of the curriculum at 42 School. Use of this code must comply with the school's academic integrity policies.
