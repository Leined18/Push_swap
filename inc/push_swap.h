#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				num;
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

t_stack				*ft_new(int num);
void				ft_add_back(t_stack **stack, t_stack *new_node);
void				ft_add_front(t_stack **stack, t_stack *new_node);
void				ft_load_stack(int argc, char **argv, t_stack **stack);
void				ft_swap(int *a, int *b);
void				free_stack(t_stack *A);
void				push(t_stack **stack, int num, int index);
void				splitStack(t_stack *stack, t_stack **left, t_stack **right);
t_stack				*mergeStacks(t_stack *left, t_stack *right, int k);
void				mergeSortKSorted(t_stack **stack, int k);
#endif