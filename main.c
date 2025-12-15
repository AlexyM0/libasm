#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "libasm.h"
#include <stdlib.h>

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

    printf("--------\n");

    errno = 0;
    ssize_t w1 = ft_write(1, "ft_write: Hello\n", strlen("ft_write: Hello\n"));
    printf("ft_write ret = %zd | errno=%d (%s)\n", w1, errno, strerror(errno));

    errno = 0;
    ssize_t w2 = write(1, "write:    Hello\n", strlen("write:    Hello\n"));
    printf("write    ret = %zd | errno=%d (%s)\n", w2, errno, strerror(errno));

    printf("--------\n");

    errno = 0;
    ssize_t w3 = ft_write(-1, "X\n", 2);
    printf("ft_write(-1) ret = %zd | errno=%d (%s)\n", w3, errno, strerror(errno));

    errno = 0;
    ssize_t w4 = write(-1, "X\n", 2);
    printf("write(-1)    ret = %zd | errno=%d (%s)\n", w4, errno, strerror(errno));

    printf("--------\n");

    int fd = open("main.c", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    char b1[32] = {0};
    char b2[32] = {0};

    errno = 0;
    ssize_t rread1 = ft_read(fd, b1, 20);
    printf("ft_read ret = %zd | errno=%d (%s) | buf=\"%.*s\"\n",
           rread1, errno, strerror(errno), (int)(rread1 > 0 ? rread1 : 0), b1);

    lseek(fd, 0, SEEK_SET);

    errno = 0;
    ssize_t rread2 = read(fd, b2, 20);
    printf("read    ret = %zd | errno=%d (%s) | buf=\"%.*s\"\n",
           rread2, errno, strerror(errno), (int)(rread2 > 0 ? rread2 : 0), b2);

    close(fd);

    printf("--------\n");

    errno = 0;
    ssize_t rerr1 = ft_read(-1, b1, 10);
    printf("ft_read(-1) ret = %zd | errno=%d (%s)\n", rerr1, errno, strerror(errno));

    errno = 0;
    ssize_t rerr2 = read(-1, b2, 10);
    printf("read(-1)    ret = %zd | errno=%d (%s)\n", rerr2, errno, strerror(errno));

    printf("--------\n");

    errno = 0;
    char *d1 = ft_strdup("Hello malloc via strdup!");
    printf("ft_strdup ret=%p | errno=%d (%s) | str=\"%s\"\n",
           (void*)d1, errno, strerror(errno), d1 ? d1 : "(null)");

    errno = 0;
    char *d2 = strdup("Hello malloc via strdup!");
    printf("strdup    ret=%p | errno=%d (%s) | str=\"%s\"\n",
           (void*)d2, errno, strerror(errno), d2 ? d2 : "(null)");

    free(d1);
    free(d2);
    
    return 0;
}
