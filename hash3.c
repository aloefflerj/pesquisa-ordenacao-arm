#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 11

struct DataItem
{
    int data;
    int key;
};

struct DataItem *hashArray[SIZE];
struct DataItem *dummyItem;
struct DataItem *item;

int hash(int key) {
    return key % SIZE;
}

int insert(int key, int data) {

    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));

    item->key = key;
    item->data = data;
    
    int hashIndex = hash(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {

        hashIndex++;

        hashIndex  %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem *search(int key) {

    int hashIndex = hash(key);

    while (hashArray[hashIndex] != NULL) {
        
        if(hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }

        hashIndex++;

        hashIndex %= SIZE;
    }

    return NULL;
}

struct DataItem *delete(struct DataItem *item) {

    int key = item->key;

    int hashIndex = hash(key);

    while(hashArray[hashIndex] != NULL ) {

        if(hashArray[hashIndex]->key == key) {
            struct DataItem *temp = hashArray[hashIndex];

            hashArray[hashIndex] = dummyItem;
            return temp; 
        }

        hashIndex++;

        hashIndex %= SIZE;
    }

    return NULL;
}

void printHashArray() {
    int i = 0;

    for(int i = 0; i < SIZE; i++) {
        if(hashArray[i] != NULL) {
            printf(" (%d, %d)", hashArray[i]->key, hashArray[i]->data);
        }else {
            printf(" ~~ ");
        }
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem->key = -1;
    dummyItem->data = -1;
    
    insert(1, 20);
    insert(42, 80);
    insert(12, 44);
    insert(37, 97);

    printHashArray();

    item = search(37);

    if(item != NULL) {
        printf("Element %d found!\n", item->data);
    }else {
        printf("Element not found\n");
    }

    

    return 0;
}
 