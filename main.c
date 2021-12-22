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

typedef struct tree_node{
    uint32_t id;
    struct tree_node* child[MaxL];
    record* contents;
    uint32_t leaf;
    void **pointers;
    int *keys;
    struct node *parent;
    bool is_leaf;
    int num_keys;
    struct node *next;
}tree_node;


uint32_t converter_int(char arr[]){
    uint32_t num =0;
    for(uint32_t x=0; arr[x] != "/0"; x++){
        num = 10 * num + (arr[x] - '0');
    }
}

tree_node* make_node(void){
    tree_node* new_node;
    new_node = malloc(sizeof(tree_node));
    if(new_node == NULL){
        printf("Error in node creation");
        exit(1);
    }
    new_node -> keys = malloc(sizeof(MaxL -1) * sizeof(int));
    if(new_node->keys == NULL){
        printf("Error in new node keys array");
        exit(1);
    }
    new_node ->pointers = malloc(sizeof(MaxL)* sizeof(void*));
    if(new_node->pointers == NULL){
        printf("Error in new node pointers array");
        exit(1);
    }
    new_node->is_leaf = false;
    new_node->num_keys = 0;
    new_node -> parent = NULL;
    new_node-> next = NULL;
    return new_node;
}

tree_node* make_leaf(void){
    tree_node *leaf = make_node();
    leaf-> is_leaf = true;
    return leaf;
}

tree_node *new_tree(int key, record* pointer){
    tree_node* root = make_leaf();
    root->keys[0] = key;
    root-> pointers[0] = pointer;
    root -> pointers[MaxL -1] = NULL;
    root -> num_keys++;
    return root;
}

int main(int argc, char *argv[]) {

    printf("Size of struct; %lu\n", sizeof(record));

    return 0;
}

