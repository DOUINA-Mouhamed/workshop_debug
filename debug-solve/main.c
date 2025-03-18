#include "my_ls.h"
#include "lib.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int which_flag(char c, char *flags)
{
    int count;

    for (count = 0; *flags != c; ++flags, ++count);
    if (!flags)
        return (-1);
    return count;
}

int scan_string(char *str, int *flags, char *flags_list)
{
    int pos;
    while (str) {
        pos = which_flag(*str, flags_list);
        if (pos < 0)
            return (-1);
        *flags |= 1 << pos;
        ++str;
    }
    return 0;
}

struct flags_t find_flag(char **av, linked_list_t **list)
{
    struct flags_t flags;
    char *flags_list = FLAGS_LIST;

    flags.values = 0;
    ++av;
    while (av) {
        if (**av == '-') {
            ++(*av);
            scan_string(*av, &flags.values, flags_list);
        }
        else {
            *list = new_node(*list, *av);
        }
        ++av;
    }
    return flags;
}

int main(int ac, char **av)
{
    char a[] = "test, here, \"long test here\", \"second one\"";
    linked_list_t *list = NULL;
    struct flags_t my_flags;

    char *str = my_strstr(av[1], av[2]);
    my_put_str(str);

    print_array(av);
    av = sort_array(av);
    print_array(av);

    char **sorted = str_to_word_array(av[1]);
    my_flags = find_flag(av, &list);
    destroy_list(list);

    list = new_list(av);
    my_sort_list(&list, &strcmp);
    destroy_list(list);
    
    sorted = str_to_word_array(a);
    sorted = sort_array(sorted);
    print_array(sorted);
    destroy_array(sorted);

    return 0;
}
