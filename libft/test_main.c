#include <stdio.h>
#include "inc/libft.h"
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    int arr[] = {1, 2, 3, 4, 5};

    printf("Original string: %s\n", str);
    ft_memrev(str, strlen(str));
    printf("Reversed string: %s\n", str);

    printf("Original array: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ft_memrev(arr, sizeof(arr));

    printf("Reversed array: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
