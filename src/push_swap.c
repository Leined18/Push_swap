#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		printf("A: %d\n", current->num);
		current = current->next;
	}
}

void	free_stack(t_stack *A)
{
	t_stack	*temp;

	while (A != NULL)
	{
		temp = A;
		A = A->next;
		free(temp);
	}
}

int	main(int ac, char **av)
{
	t_stack	*A;

	if (ac == 1)
		ft_error("", 1);
	A = NULL;
	ft_load_stack(ac, av, &A);
	printList(A);
	free_stack(A);
	return (0);
}
