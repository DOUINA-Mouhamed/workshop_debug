#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

int my_strlen(char *str)
{
    return 1 + (*str ? my_strlen(str + 1) : 0);
}

void my_put_str(char *str)
{
    write(1, str, strlen(str));
}

int my_strcmp(char *s1, char *s2)
{
    for (; *s2 && *s1 == *s2; s1++, s2++);
    return (*s1 - *s2);
}

char *my_strstr(char *str1, char *str2)
{
    while (str1) {
        if (!strncmp(str1, str2, my_strlen(str2)))
            return str1;
        str2++;
    }

    return NULL;
}