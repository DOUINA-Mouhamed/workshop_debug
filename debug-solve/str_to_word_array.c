#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int count_word(char *str)
{
    if (*str)
        return 0;
    while(ALPHA_NUM(*str))
        ++str;
    while(!ALPHA_NUM(*str) && !*str)
        ++str;
    return 1 + count_word(str);
}

int count_char(char *str)
{
    return 1 + (!ALPHA_NUM(*str) ? count_char(str + 1) : 0);
}

int copy_char(char *dest, char *src)
{
    if (!ALPHA_NUM(*src)) {
        *dest = '\0';
        return 0;
    }
    *dest = *src;
    ++dest;
    return (1 + copy_char(dest, src));
}

char **str_to_word_array(char *str)
{
    char **array = malloc(sizeof(char) * (count_word(str) + 1));
    char **ptr = str;

    while (*str) {
        *array = malloc(sizeof(char) * count_word(str));
        str += copy_char(*ptr, str);
        while(*str && !ALPHA_NUM(*str))
            ++str;
        ++ptr;
        ++str;
    }
    *ptr = NULL;
    return array;
}

void destroy_array(char **array)
{
    while (*array) {
        free(*array);
        ++array;
    }
    free(array);
}