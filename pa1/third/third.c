#include <stdio.h>
#include <stdlib.h>
#define numBuckets 10000


typedef struct node{
    int data;
    struct node* next;
} node;


int hash(int key){
    int position;
    position = key % numBuckets;
    if(position < 0){
        position = position + numBuckets;
    }
    return position;
}

int searchHashTable(node* hashTable[], int key){
    node* ptr;
    int position;
    position = hash(key);
    ptr = hashTable[position];
    while(ptr != NULL){
        if(ptr->data == key){
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

int insertHashTable(node* hashTable[], int key){
    node* ptr;
    int position;
    position = hash(key);
    if(hashTable[position] != NULL){
        if(searchHashTable(hashTable, key) == 1)
        {
            return 1;
        }
        else
        {
            ptr = (node*) malloc(sizeof(node));
            ptr->data = key;
            ptr->next = hashTable[position];
            hashTable[position] = ptr;
            return 1;
        } 
    }
    else
    {
        ptr = (node*) malloc(sizeof(node));
        ptr->data = key;
        ptr->next = hashTable[position];
        hashTable[position] = ptr;
        return 0;
    }
}

void freeHashTable(node* hashTable[]){
    int i = 0;
    node *p, *q;
    for(i = 0; i < numBuckets; i++)
    {
        p = hashTable[i];
        while(p != NULL){
            q = p;
            p = p->next;
            free(q);
        }
    }
}


int main(int argc, char** argv){
    FILE *fp;
    char c;
    int value, numCollisions, numSearches;
    node* HashTable[numBuckets];
    int i;
    for(i = 0; i < numBuckets; i++)
    {
        HashTable[i] = NULL;
    }	

    fp = fopen(argv[1], "r");
    numCollisions = 0;
    numSearches = 0;

    while(!feof(fp))
    {
        if(fscanf(fp, "%c\t%d\n", &c, &value) == 2)
        {
            if(c == 'i')
            {
                if(insertHashTable(HashTable, value))
                {
                    numCollisions++;
                }

            }
            if(c == 's')
            {
                if(searchHashTable(HashTable, value))
                {
                    numSearches++;
                }
            }
        }
        
    }
    fclose(fp);

    printf("%d\n%d\n", numCollisions, numSearches);
    freeHashTable(HashTable);
    return 0;
}


