
#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*static_str;
	char		*start;
	char		*end;

	if (str)
		static_str = str;
	if (!static_str)
		return (NULL);
	start = static_str;
	while (*start && ft_strchr(delim, *start))
		start++;
	if (!*start)
	{
		static_str = NULL;
		return (NULL);
	}
	end = start;
	while (*end && !ft_strchr(delim, *end))
		end++;
	if (*end)
	{
		*end = '\0';
		static_str = end + 1;
	}
	else
		static_str = NULL;
	return (start);
}