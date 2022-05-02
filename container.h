typedef struct container{
    int id;
    struct container* next;
}Container;

typedef struct stack{
    int size;
    Container* top;
}Stack;

int is_stack_full(Stack);
int is_in_stack(Stack, int);

void stack_into(Stack*, int);
int unstack_from(Stack*, int);