#include <stdio.h>
#include "libasm.h"

int main(void)
{
    const char *s = "Hello";
    size_t len = ft_strlen(s);

    printf("len = %zu\n", len);
    return 0;
}
