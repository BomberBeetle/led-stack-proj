#include <stdlib.h>
#include <stdio.h>

#include "container.h"

int try_put(int id, Stack* stacks){

    int min_size = 99999, min_index = -1;

    for(int i = 0; i < 4; i++){
        if(is_in_stack(stacks[i], id)) return -1;

        if(stacks[i].size < min_size ){
            min_size = stacks[i].size;
            min_index = i;
        }
    }

    if(min_size >= 3) return -2;

    stack_into(&stacks[min_index], id);
    return 0;    
}

int try_remove(int id, Stack* stacks){
    for(int i = 0; i < 4; i++){
        if(is_in_stack(stacks[i], id)){
            int result = unstack_from(&stacks[i], id);
            if(result == -1){
              return -2;  
            }
            else if(result == -2){
                return -3;
            }
            return 0;
        }
    }
    return -1;
}

int main(int argc, char** argv){
    Stack stacks[4] = {{0,NULL},{0,NULL},{0,NULL},{0,NULL}};
    int opt_in, result;
    while(1){
        scanf("%d", &opt_in);
        switch (opt_in){
            case 1:
                printf("id para empilhar: ");
                scanf("%d", &opt_in);
                result = try_put(opt_in, stacks);
                if(result == -1) printf("Erro: id já está presente em uma das pilhas.\n");
                else if(result == -2) printf("Erro: todas as pilhas estão cheias\n");
                else printf("Empilhado com sucesso.\n");
                break;
            case 2:
                printf("id para remover: ");
                scanf("%d", &opt_in);
                result = try_remove(opt_in, stacks);
                if(result == -1)printf("Erro: id não está presente em nenhuma pilha.\n");
                else if(result == -2)printf("Erro: id está em uma pilha, mas não está no topo.\n");
                else printf("Removido com sucesso.\n");
                break;
            case 3:
                return 0;
                break;
            default:
                break;
        }
    }
}