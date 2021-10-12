#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define TABLE_SIZE 11

int *hashTable[TABLE_SIZE];

int hash(int value) {
    return (value * value * value) % TABLE_SIZE;
}

void initTable() {
    int i;
    for(i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void printTable() {
    int i = 0;
    printf("\n<<<<<<<<<<<<< Table Start >>>>>>>>>>>>>\n");
    for (i = 0; i < TABLE_SIZE; i ++) {

        if(hashTable[i] == NULL){
            printf("\n\t%d\t~~~~", i);
        }else {
            printf("\n\t%d\t%d", i, *hashTable[i]);
        }

    }
    printf("\n<<<<<<<<<<<<< Table End >>>>>>>>>>>>>\n");
}

bool addToTable(int *value) {
    int i, hashIndex;

    if(&value == NULL) {
        return false;
    }
    hashIndex = hash(*value);

    for(i = 0; i <  TABLE_SIZE; i++){
        if(hashTable[hashIndex] == NULL) {
            hashTable[hashIndex] = value;
            return true;
        }
    }

    return false;
    
}

int main(int argc, char const *argv[])
{
    int totalNumbers;

    printf("\n\n\n%d\n\n\n", (2 % 2));

    printf("=======================");
    printf("\n|| ## Hash Table ## ||\n");
    printf("=======================");
    printf("\n");
    printf("\nPor favor, insira a quantidade de números a serem armazenados: ");
    scanf("%d", &totalNumbers);

    initTable();
    printTable();

    int a = 5;
    addToTable(a);
    addToTable(4);
    addToTable(3);
    addToTable(2);
    addToTable(1);

    printTable();

    printf("%d", *hashTable[1]);

    printf("\n");
    return 0;
}
