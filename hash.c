#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TABLESIZE 11

struct DataItem
{
    int data;
    int key;
};

struct DataItem *hashArray[TABLESIZE];
struct DataItem *deletedItem;
struct DataItem *item;

int hash(int key) {

    if(key == 0 || key == 1) {
        key += 2;
    }
    return (key * key * key) % TABLESIZE;
}

int insert(int key, int data, int count, int hashIndex) {

    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));

    item->key = key;
    item->data = data;
    
    if(count == 0) {
        hashIndex = hash(key);
    }else {
        hashIndex = hash(hashIndex);
    }

    if(hashArray[hashIndex] == NULL || hashArray[hashIndex]->key == -1){
        hashArray[hashIndex] = item;
        return count+1;
    }

    hashIndex++;
    insert(key, data, count+1, hashIndex);

}

struct DataItem *search(int key, int count, int hashIndex) {

    if(count == 0) {
        hashIndex = hash(key);
    }else {
        hashIndex = hash(hashIndex);
    }

    if(hashArray[hashIndex] == NULL) {
        printf("Elemento na chave %d nao encontrado", key);
        return NULL;
    }

    if(hashArray[hashIndex]->key == key) {
        printf("\nElemento %d encontrado na chave %d | numero de tentativas = %d", hashArray[hashIndex]->data, key, count+1);
        return hashArray[hashIndex];
    }
    


    hashIndex++;
    item = search(key, count+1, hashIndex);

    return item;
}

struct DataItem *delete(struct DataItem *item, int count, int hashIndex) {

    int key = item->key;
    struct DataItem *temp;

    if(count == 0) {
        hashIndex = hash(key);
    }else {
        hashIndex = hash(hashIndex);
    }

    if(hashArray[hashIndex] == NULL) {
        return NULL;
    }

    if(hashArray[hashIndex]->key == key) {
        temp = hashArray[hashIndex];

            hashArray[hashIndex] = deletedItem;
            return temp;
    }

    hashIndex++;
    temp = delete(item, count+1, hashIndex);

    return temp;
}

void printHashArray() {
    int i;

    for(i = 0; i < TABLESIZE; i++) {
        if(hashArray[i] != NULL) {
            if(hashArray[i]->key == -1) {
                printf("| [deleted] ");
            }else {
                printf("| [%d => %d] ", hashArray[i]->key, hashArray[i]->data);
            }
        }else {
            printf("| xx ");
        }
    }

    printf("\n");
}

void printMenu() {
    printf("\n=======================");
    printf("\n|| ## Hash Table ## ||\n");
    printf("=======================");
    printf("\n");
    printf("\nPor favor, escolha uma opcao\n");
    printf("\n#1.Imprimir array de hash");
    printf("\n#2.Localizar a partir do índice do array");
    printf("\n#3.Deletar a partir do índice do array");
    printf("\n#4.Sair");
}

void readToMemory(int qtyNumbers) {
    int i, value, count;
    for(i = 0; i < qtyNumbers; i++) {
        printf("\nDigite o número na posicao %d do array: ", i);
        scanf("%d", &value);
        count = insert(i, value, 0, 0);
        printf("Numero %d inserido no indice %d -> algoritmo de hash usado %d vez(es)\n", value, i, count);
    }
}

int main(int argc, char const *argv[])
{
    deletedItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    deletedItem->key = -1;
    deletedItem->data = -1;

    int qtyNumbers, op, index, yOrN;

    while(qtyNumbers > 11 || qtyNumbers < 1) {

        printf("\n=======================");
        printf("\n|| ## Hash Table ## ||\n");
        printf("=======================");
        printf("\n");
        printf("\nPor favor, insira a quantidade de números a serem armazenados (maximo %d): ", TABLESIZE);
        scanf("%d", &qtyNumbers);

    }

    readToMemory(qtyNumbers);

    while (op != 4)
    {
        printMenu();
        printf("\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("\n## Array de Hash ##\n");
                printHashArray();
                break;
            case 2:
                printf("\nInsira a chave do número que procura: ");
                scanf("%d", &index);
                printf("\nLocalizando... ");
                item = search(index, 0, 0);
                break;
            case 3:
                printf("\nInsira a chave do número que deseja deletar: ");
                scanf("%d", &index);
                printf("\nLocalizando... ");
                item = search(index, 0, 0);
                if(item != NULL) {
                    printf("\nDeseja deletar o elemento %d? \n#1.Sim\n#2.Nao\n\n", item->data);
                    scanf("%d", &yOrN);
                    if(yOrN == 1) {
                        item = delete(item, 0, 0);
                        printf("\nElemento %d deletado com sucesso!", item->data);
                    }
                }
                break;
        }
    }
    
    return 0;

}