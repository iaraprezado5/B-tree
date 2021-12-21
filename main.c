//Implemente um B+ Tree, assume registos de 708bytes e blocos (blocks) de 4Kbytes, a chave (key) é um inteiro de 32 bits (int32_t).

//Input is a file with the following structure (seperated by ;), where each line is a record. First line must be ignored.

#define MaxM 5 //size of the tree arrays
#define MaxL 5 //size of linked list
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

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
}tree_node;


uint32_t converter_int(char arr[]){
    uint32_t num =0;
    for(uint32_t x=0; arr[x] != "/0"; x++){
        num = 10 * num + (arr[x] - '0');
    }
}

int main(int argc, char *argv[]) {

    printf("Size of struct; %lu\n", sizeof(record));

    return 0;
}



