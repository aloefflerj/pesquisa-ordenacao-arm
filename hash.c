#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 11
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFUL)

//old
typedef struct
{
    char name[MAX_NAME];
    int age;
} person;

//new
int *hashTable2[TABLE_SIZE];

//old
person *hash_table[TABLE_SIZE];

//new
int hash2(int value)
{
    int hashValue = 0;

    hashValue = (value * value * value) % TABLE_SIZE;
    return hashValue % TABLE_SIZE;
}

//old
unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        // printf("%c\n", name[i]);
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

//new
void initHashTable2()
{
    int i = 0;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        hashTable2[i] = NULL;
    }
}

//old
void init_hash_table()
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

//new
void printHashTable2()
{
    int i = 0;
    // printf("\nhashtable 0 => %d", *hashTable2[1]);

    printf("\n<<<<<<<<<<<<< Table Start >>>>>>>>>>>>>\n");

    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable2[i] == NULL)
        {
            printf("\t%d\t---\n", i);
        }
        // else if (hashTable2[i] == DELETED_NODE)
        // {
        //     printf("\t%d\t<deleted>n", i);
        // }
        else
        {
            printf("\t%d\t%p\n", i, hashTable2[i]);
        }
    }

    printf("<<<<<<<<<<<<< Table End >>>>>>>>>>>>>\n");
}

//old
void print_table()
{
    int i;
    printf("Start--------------------------->\n");
    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%d\t---\n", i);
        }
        else if (hash_table[i] == DELETED_NODE)
        {
            printf("\t%d\t<deleted>\n", i);
        }
        else
        {
            printf("\t%d\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End----------------------------->\n");
}

//new
bool hashTableInsert2(int value)
{
    int i = 0;
    printf("\nmaAQUSIU -> %d\n", value);
    if (&value == NULL)
    {
        printf("\n %d -> false", value);
        return false;
    }
    int index = hash2(value);
    printf("\n%d hashed into %d", value, index);

    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable2[i] == NULL)
        {
            hashTable2[index] = &value;
            printf("\nValor no endereco %d => %d", index, value);
            return true;
        }
    }
    // for (i = 0; i < TABLE_SIZE; i++)
    // {
    //     int try = (i + index) % TABLE_SIZE;
    //     if (&hashTable2[try] == NULL)
    //     {
    //         hashTable2[try] = &value;
    //         return true;
    //     }
    // }

    return false;
}

//old
bool hash_table_insert(person *p)
{
    int i;
    if (p == NULL)
        return false;
    int index = hash(p->name);
    for (i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup(char *name)
{
    int i, index = hash(name);
    for (i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + 1) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return false;
        }
        if (hash_table[try] == DELETED_NODE)
            continue;

        if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
        {
            return hash_table[try];
        }
    }
    return NULL;
}

person *hash_table_delete(char *name)
{
    int i, index = hash(name);
    for (i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + 1) % TABLE_SIZE;

        if (hash_table[try] == NULL)
            return NULL;
        if (hash_table[try] == DELETED_NODE)
            continue;

        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
        {
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

void loadNumbersToMemory(int qty, int *arr)
{
    int i = 0;

    for (i = 0; i < qty; i++)
    {
        printf("\nInsira o número na posição %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
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

    initHashTable2();
    printHashTable2();

    // int *allValues[totalNumbers];

    // loadNumbersToMemory(totalNumbers, *allValues);

    hashTableInsert2(5);
    hashTableInsert2(4);
    hashTableInsert2(3);
    hashTableInsert2(2);
    hashTableInsert2(1);

    printHashTable2();

    return 0;

    init_hash_table();
    print_table();

    person anderson = {.name = "Anderson", .age = 27};
    person susan = {.name = "Susan", .age = 27};
    person matcha = {.name = "Matcha", .age = 4};
    person alice = {.name = "Alice", .age = 5};
    person melanie = {.name = "Melanie", .age = 2};
    person rockjr = {.name = "Rock Jr", .age = 11};
    person gaia = {.name = "Gaia", .age = 8};
    person greta = {.name = "Greta", .age = 6};
    person dominique = {.name = "Dominique", .age = 6};
    person woody = {.name = "Woody", .age = 6};

    hash_table_insert(&anderson);
    hash_table_insert(&susan);
    hash_table_insert(&matcha);
    hash_table_insert(&alice);
    hash_table_insert(&melanie);
    hash_table_insert(&rockjr);
    hash_table_insert(&gaia);
    hash_table_insert(&greta);
    hash_table_insert(&dominique);
    hash_table_insert(&woody);
    print_table();

    person *tmp = hash_table_lookup("Alice");
    if (tmp == NULL)
    {
        printf("Not found!\n");
    }
    else
    {
        printf("Found %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("Dominique");
    if (tmp == NULL)
    {
        printf("Not found!\n");
    }
    else
    {
        printf("Found %s.\n", tmp->name);
    }

    hash_table_delete("Dominique");

    tmp = hash_table_lookup("Dominique");
    if (tmp == NULL)
    {
        printf("Not found!\n");
    }
    else
    {
        printf("Found %s.\n", tmp->name);
    }

    print_table();

    return 0;
}
