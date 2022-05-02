#include "container.h"

#include <stdlib.h>

int is_stack_full(Stack s){
    if(s.size >= 3){
        return 1;
    }
    else{
        return 0;
    }
}

int is_in_stack(Stack s, int id){
    Container *cur = s.top;
    while(cur != NULL){
        if(cur->id == id) return 1;
        cur = cur->next;
    }
    return 0;
}

void stack_into(Stack* s, int id){
    Container* newContainer = malloc(sizeof(Container));
    newContainer->id = id;
    newContainer->next = s->top;
    s->top = newContainer;
    s->size++;
}

int unstack_from(Stack* s, int id){
    if(s->top != NULL){
        if(s->top->id == id){
            Container* newTop = s->top->next;
            free(s->top);
            s->top = newTop;
            s->size--;
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        return -2;
    }

}