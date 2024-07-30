#include "libft.h"

void	put2d(void **arr, char whitespace, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c)
	{
		j = 0;
		while (((char *)arr[i])[j] != '\0')
		{
			write(1, &((char *)arr[i])[j], 1);
			j++;
		}
		if (i < c - 1)
			write(1, &whitespace, 1);
		i++;
	}
}
