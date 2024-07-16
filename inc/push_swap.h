#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

// operations

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				ft_swap(int *a, int *b);

// stack utils

t_stack				*ft_new(int num);
void				ft_add_back(t_stack **stack, t_stack *new_node);
void				ft_add_front(t_stack **stack, t_stack *new_node);
void				ft_load_stack(t_stack **stack, int argc, char **argv);
void				ft_stack_zero(t_stack **stack, int argc);
void				free_stacks(t_stack *a, int size);

#endif