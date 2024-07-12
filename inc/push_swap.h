#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*ft_new(int num);
void				ft_add_back(t_stack **stack, t_stack *new_node);
void				ft_add_front(t_stack **stack, t_stack *new_node);
void				ft_load_stack(int argc, char **argv, t_stack **stack);

#endif