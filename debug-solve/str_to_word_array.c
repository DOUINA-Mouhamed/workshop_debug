#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int count_word(char *str)
{
    int isString = 0;
    int count = 0;

    while (*str) {
        while((ALPHA_NUM(*str) || isString) && *str) {
            if (QUOTE(*str)) {
                isString ^= 1;
            }
            ++str;
        }
        count++;
        while(!ALPHA_NUM(*str) && *str)
            ++str;
    }
    return count;
}

int count_char(char *str)
{
    int isString = 0;
    char *ptr = str;

    while((ALPHA_NUM(*str) || isString) && *str) {
        if (QUOTE(*str)) {
            isString ^= 1;
        }
        ++str;
    }
    return str - ptr;
}

int copy_char(char *dest, char *src)
{
    int isString = 0;
    char *ptr = dest;

    while((ALPHA_NUM(*src) || isString) && *src) {
        if (QUOTE(*src)) {
            isString ^= 1;
        }
        *dest = *src;
        ++src;
        ++dest;
    }
    *dest = '\0';
    return dest - ptr;
}

char **str_to_word_array(char *str)
{
    char **array = malloc(sizeof(char*) * (count_word(str) + 1));
    char **ptr = array;

    while (*str) {
        *ptr = malloc(sizeof(char) * count_char(str) + 1);
        
        str += copy_char(*ptr, str);
        while(*str && !ALPHA_NUM(*str))
            ++str;
        ++ptr;
    }
    *ptr = NULL;
    return array;
}

void destroy_array(char **array)
{
    char **ptr = array;
    char *tmp;

    while (*array) {
        tmp = *array;
        ++array;
        free(tmp);
    }
    free(ptr);
}

void print_array(char **array)
{
    while (*array) {
        write(1, *array, strlen(*array));
        write(1, "\n", 1);
        ++array;
    }
}