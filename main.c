//Implemente um B+ Tree, assume registos de 708bytes e blocos (blocks) de 4Kbytes, a chave (key) é um inteiro de 32 bits (int32_t).

//Input is a file with the following structure (seperated by ;), where each line is a record. First line must be ignored.

#define MaxM 5 //size of the tree arrays
#define MaxL 5 //size of linked list
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct record {
    uint32_t id;
    char firstname[100];
    char surname[100];
    char birthdate[11];
    char Country[50];
    char CountryCode[3];
    char City[50];
    char died[11];
    char gender[7];
    uint32_t year;
    char category[12];
    uint32_t share;
    char motivation[350];
} record;

typedef struct list_node{
    struct list_node* next;
    record* contents;
    struct list_node* prev;
    uint32_t leaf;
}list_node;

typedef struct tree_node{
    uint32_t id;
    struct tree_node* child;
    list_node* list;
    struct tree_node* next;
}tree_node;

int size_list(list_node * list_position){
    int tamanho;
    while(list_position ->next != NULL){
        tamanho++;
    }
    tamanho++;
    return tamanho;
}

int size_array(tree_node arr[]){
    int tamanho_arr;
    while(arr -> next != NULL){
        arr = arr -> next;
        tamanho_arr++;
    }
    tamanho_arr++;
    return tamanho_arr;
}
int add_node(tree_node arr[], record* node){
    if(size_array(arr) < MaxM){
        //adicionar node
    }
    else{
        //split
        //adicionar node
    }

}

int insert_node(record* node, tree_node arr[]){
    if (node == NULL){
        return 0;
    }
    int aux;
    if ((&arr[0])->child == NULL) {
        for (int i = 0; i != MaxM; i++){
            if (node->id < (&arr[i])->list->contents->id){
                aux = i - 1;
                break;
            }//descobrir indice
            else {
                aux = i;
            }
        }
        list_node* list_position = (&arr)[aux]->list;
        list_node* node_position = (&arr)[aux]->list;
        for (; node_position->next != NULL; node_position = node_position->next) {
            if (node->id < node_position->next->contents->id) {
                add_node(arr, node);
                return 1;
            }
        }
        node_position = node_position->next;
        add_node(arr, node);
    }
    else {
        for (int i = 0; i != MaxM; i++) {
            if (node->id < (&arr[i])->id) {
                aux = i - 1;
                break;
            }
            else {
                aux = i;
            }
        }
        arr = (&arr[aux])->child;
        insert_node(node, arr);
    }
    return 0;
}

record* read_file(FILE* fp) {
    record* node = (record*) malloc(sizeof(record));
    if(node == NULL){
        printf("Error");
        return NULL;
    }
    fscanf(fp, " %d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%[^;];%d;%[^\n]", &node->id, node->firstname,
           node->surname, node->birthdate, node->died, node->Country, node->CountryCode, node->City,
           node->gender, &node->year, node->category, &node->share, node->motivation);
    return node;
}

//root inicial
int rootInicial(tree_node arr[]){
    int Keys = 0;
    list_node e;
    
    //percorrer os primeiros 5 elementos
    for(e = arr[Keys]; Keys != 4; Keys++){
        //bubblesort
    }
    //chamar o insertnode
}

int main(int argc, char *argv[]) {
    FILE *fp = fopen("nobel_prizes_projeto.csv", "r");
    printf("Size of struct; %lu\n", sizeof(record));
    insert_node(read_file(fp));
    return 0;
}


