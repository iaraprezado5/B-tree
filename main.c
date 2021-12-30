//Implemente um B+ Tree, assume registos de 708bytes e blocos (blocks) de 4Kbytes, a chave (key) é um inteiro de 32 bits (int32_t).

//Input is a file with the following structure (seperated by ;), where each line is a record. First line must be ignored.

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
    uint32_t leaf;
}list_node;

typedef struct tree_node{
    uint32_t id;
    struct tree_node* child;
    struct tree_node* parent;
    list_node* list;
    struct tree_node* next;
    int *keys;

}tree_node;

int size_list(list_node * list_position){
    int size;
    while(list_position ->next != NULL){
        size++;
    }
    size++;
    return size;
}

int size_array(tree_node arr[]){
    int size_arr;
    while(arr -> next != NULL){
        arr = arr -> next;
        size_arr++;
    }
    size_arr++;
    return size_arr;
}

tree_node* insert_into_leaf(tree_node* leaf, record* node){
    int i;
    int insertion_point = 0;
    while((insertion_point < leaf->id < leaf->keys[insertion_point+1]) && (leaf->keys[insertion_point] < leaf->keys[insertion_point+1])){
        insertion_point++;
    }
    for(;leaf->id > insertion_point; i--){
        leaf -> keys[leaf->id] = leaf -> keys[leaf->id -1];
        leaf-> keys++;
    }
    leaf->keys[insertion_point] = node;
    return leaf;
}

tree_node* make_leaf(void){
    tree_node* new_leaf;
    new_leaf = malloc(sizeof(tree_node));
    if(new_leaf == NULL){
        printf("Error");
        return NULL;
    }
    new_leaf->keys = 0;
    new_leaf->parent = NULL;
    new_leaf->next = NULL;
    return new_leaf;
};


int add_node(tree_node arr[], record* node){
    if(size_array(arr) < MaxM){
        insert_into_leaf(make_leaf(), node);
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
    printf("%d", node);
    return node;
}



int main(int argc, char *argv[]) {
    FILE *fp = fopen("nobel_prizes_projeto.csv", "r");
    //printf("Size of struct; %lu\n", sizeof(record));
    insert_node(read_file(fp));
    return 0;
}



