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
		ft_printf("(%d) ", current->num);
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		ft_error("", 1);
	ft_load_stack(&a, ac, av);
	ft_stack_zero(&b, ac);
	printf("Pila antes de ordenar:\n");
	print_stack(a);
	print_stack(b);
	ft_printf("size a %d , b %d\n", a->size, b->size);
	free_stack(a, a->size);
	free_stack(b, b->size);
	ft_successful("liberada");
	return (0);
}
