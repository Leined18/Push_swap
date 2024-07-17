#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef int			t_bool;
# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	long			num;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;

// sort_d

void				sort(t_stack *a, t_stack *b, int length);

// checks

int					is_sorted(t_stack *stack);
void				check(int argc, char **argv);

// operations

void				reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void				swap_both(t_stack *stack1, t_stack *stack2);
void				rotate_both(t_stack *stack_a, t_stack *stack_b);
void				push(t_stack *stack1, t_stack *stack2, char x, t_bool b);
void				push_stack(t_stack *stack1, t_stack *stack2);
void				swap(t_stack *stack, char x, t_bool b);
void				rotate(t_stack *stack, char x, t_bool b);
void				reverse_rotate(t_stack *stack, char x, t_bool b);

// stack utils

t_stack				*ft_new(int num);
void				ft_add_back(t_stack **stack, t_stack *new_node);
void				ft_add_front(t_stack **stack, t_stack *new_node);
void				ft_load_stack(t_stack **stack, int argc, char **argv);
void				free_stacks(t_stack *a, t_stack *b, int size);
void				print_stack(t_stack *a, t_stack *b);

#endif