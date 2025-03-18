
#define CAPS(x) (x >= 'A' && x <= 'Z')
#define LOW(x) (x >= 'a' && x <= 'z')
#define NUM(x) (x >= '0' && x <= '9')

#define ALPHA_NUM(x) (CAPS(x) || LOW(x) || NUM(x))

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t, *link_t;

void my_sort_list(linked_list_t**, int(*)());
void destroy_list(linked_list_t*);
linked_list_t *new_list(char**);
linked_list_t *get_last(linked_list_t*);
linked_list_t *new_node(linked_list_t *list, void *data);

int my_strlen(char*);
int my_strcmp(char*, char*);
char *my_strstr(char*, char*);
void my_put_str(char*);

char **str_to_word_array(char*);
void destroy_array(char**);
char **sort_array(char**);
void print_array(char**);