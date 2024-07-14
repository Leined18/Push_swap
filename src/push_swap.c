#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->size == 0)
	{
		ft_printf("Pila vacía\n");
		return ;
	}
	current = stack->head;
	ft_printf("Pila: ");
	while (current != NULL)
	{
		ft_printf("(%d,%d) ", current->num, current->index);
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*A;
	int		k;

	if (ac == 1)
		ft_error("", 1);
	A = NULL;
	k = 2;
	ft_load_stack(ac, av, &A);
	printf("Pila antes de ordenar:\n");
	print_stack(A);
	mergeSortKSorted(&A, k);
	printf("\nPila ordenada:\n");
	print_stack(A);
	free_stack(A);
	return (0);
}
