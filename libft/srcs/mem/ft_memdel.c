#include "libft.h"


void ft_memdel(int num_args, ...)
{
    va_list ap;
    void **ptr;

    va_start(ap, num_args);
    while (num_args > 0)
    {
        ptr = va_arg(ap, void **);
        if (ptr != NULL && *ptr != NULL)
        {
            free(*ptr);
            *ptr = NULL;
        }
        num_args--;
    }
    va_end(ap);
}