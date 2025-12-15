#include <stdio.h>
#include <string.h>
#include "libasm.h"

int main(void)
{
    const char *s = "Hello";
    const char *s2 = "Hello";

    printf("ft_strlen len = %zu\n", ft_strlen(s));
    printf("strlen len    = %zu\n", strlen(s));

    printf("--------\n");

    int cmp = ft_strcmp(s, s2);
    printf("ft_strcmp = %d\n", cmp);

    int cmps = strcmp(s, s2);
    printf("strcmp    = %d\n", cmps);

    printf("--------\n");

    char dst1[64];
    char dst2[64];

    char *r1 = ft_strcpy(dst1, "Hello World!");
    char *r2 = strcpy(dst2, "Hello World!");

    printf("ft_strcpy dst = \"%s\" | ret=%p (dst=%p)\n", dst1, (void*)r1, (void*)dst1);
    printf("strcpy    dst = \"%s\" | ret=%p (dst=%p)\n", dst2, (void*)r2, (void*)dst2);

    return 0;
}
