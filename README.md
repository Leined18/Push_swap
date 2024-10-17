
## Project Description

**Push_swap** is a sorting program that utilizes two stacks to sort a series of integers efficiently. The program is designed to demonstrate the use of various stack operations to achieve a sorted output while minimizing the number of operations performed.

Key Concepts:
- **Stacks**: The program uses two stacks, `a` and `b`, where `a` is the primary stack containing the numbers to be sorted and `b` is used as temporary storage.
- **Operations**: A set of defined operations can be executed on the stacks to manipulate the data, including swapping, pushing, and rotating elements.

---

## Cloning Instructions

| **Command**                                     | **Description**                                    |
| -------------------------------------------------- | -------------------------------------------------- |
| `git clone --recursive git@github.com:Leined18/Push_swap.git` | Clones the Push_swap repository with submodules.   |
| `cd Push_swap`                                 | Navigates to the cloned Push_swap directory.      |
| `make all`                                     | Compiles the Push_swap project.                   |

---

## Available Operations

| **Operation**                                  | **Description**                                    |
| -------------------------------------------------- | -------------------------------------------------- |
| `sa`                                           | Swap the first two elements on stack 'a'.        |
| `sb`                                           | Swap the first two elements on stack 'b'.        |
| `ss`                                           | Execute `sa` and `sb` simultaneously.            |
| `pa`                                           | Take the first element of stack 'b' and put it on stack 'a'. |
| `pb`                                           | Take the first element of stack 'a' and put it on stack 'b'. |
| `ra`                                           | Move all elements of stack 'a' up one position.  |
| `rb`                                           | Move all elements of stack 'b' up one position.  |
| `rr`                                           | Execute `ra` and `rb` simultaneously.            |
| `rra`                                          | Move all elements of stack 'a' down one position.|
| `rrb`                                          | Move all elements of stack 'b' down one position.|
| `rrr`                                          | Execute `rra` and `rrb` simultaneously.          |

---

## Usage

| **Command**                                     | **Description**                                    |
| -------------------------------------------------- | -------------------------------------------------- |
| `ARG="numbers with spaces"; ./push_swap $ARG`      | Executes the Push_swap program with a list of numbers. |
| `./push_swap NUMBER1 NUMBER2 NUMBER3 NUMBER4 ...`  | Executes the Push_swap program with a list of numbers as parametters. |

Example Commands:
| **Command**                                     | **Description**                                    |
| -------------------------------------------------- | -------------------------------------------------- |
| `ARG="1 2 3"; ./push_swap $ARG`                | Executes Push_swap with a simple number input.    |
| `ARG="5 2 9 1"; ./push_swap $ARG`              | Executes Push_swap with a more complex input.     |

---

## Data Structures

| **Structure**                                  | **Description**                                    |
| -------------------------------------------------- | -------------------------------------------------- |
| `t_stack`                                      | Structure representing a stack, including the value and a pointer to the next element. |
| `t_command`                                    | Structure representing a command to execute, including the operation type and arguments. |

---

## Functions Overview

| **Function**                                   | **Description**                                    |
| -------------------------------------------------- | -------------------------------------------------- |
| `init_stack`                                   | Initializes a new stack and allocates memory.     |
| `push`                                         | Adds an element to the stack.                      |
| `pop`                                          | Removes and returns the top element from the stack.|
| `swap`                                         | Swaps the top two elements of a stack.            |
| `rotate`                                       | Moves all elements of the stack up by one position.|
| `reverse_rotate`                               | Moves all elements of the stack down by one position.|
| `sort_stack`                                   | Sorts the elements in the stack using an efficient sorting algorithm. |

---

## Error Handling

| **Function**                                   | **Description**                                    |
| -------------------------------------------------- | -------------------------------------------------- |
| `error_exit`                                   | Safely handles errors and exits the program.      |
| `check_duplicates`                             | Checks for duplicate values in the input.         |

---

## Testing and Validation

| **Task**                                       | **Description**                                    |
| -------------------------------------------------- | -------------------------------------------------- |
| `test_push_swap`                               | Tests the functionality of stack operations.      |
| `validate_args`                                | Validates that input arguments are integers.      |

---

## Notes
- The program only accepts integers as input and will handle invalid inputs with appropriate error messages.
- Ensure that the operations are executed in a way that follows the sorting logic to achieve the desired output.
