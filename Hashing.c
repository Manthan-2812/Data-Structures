#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Initialize hash table with -1 (indicates empty slot)
void initHashTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;  // -1 means empty
    }
    printf("Hash table initialized.\n");
    printf("-------------------------------------\n");
}

// Hash function using modulo division
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Insert using linear probing
void insert(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;
    
    // Linear probing to find empty slot
    while(hashTable[index] != -1 && hashTable[index] != -2)
    {
        // -1 = empty, -2 = deleted
        
        if(hashTable[index] == key)
        {
            printf("Key %d already exists!\n", key);
            printf("-------------------------------------\n");
            return;
        }
        
        i++;
        index = (originalIndex + i) % TABLE_SIZE;  // Linear probing
        
        if(i == TABLE_SIZE)  // Checked all slots
        {
            printf("Hash table is full! Cannot insert %d\n", key);
            printf("-------------------------------------\n");
            return;
        }
    }
    
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
    printf("-------------------------------------\n");
}

// Search for a key
void search(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;
    
    while(hashTable[index] != -1)
    {
        if(hashTable[index] == key)
        {
            printf("Key %d found at index %d\n", key, index);
            printf("-------------------------------------\n");
            return;
        }
        
        i++;
        index = (originalIndex + i) % TABLE_SIZE;
        
        if(i == TABLE_SIZE)  // Checked all slots
            break;
    }
    
    printf("Key %d not found!\n", key);
    printf("-------------------------------------\n");
}

// Delete a key (mark as deleted with -2)
void deleteKey(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;
    
    while(hashTable[index] != -1)
    {
        if(hashTable[index] == key)
        {
            hashTable[index] = -2;  // Mark as deleted
            printf("Key %d deleted from index %d\n", key, index);
            printf("-------------------------------------\n");
            return;
        }
        
        i++;
        index = (originalIndex + i) % TABLE_SIZE;
        
        if(i == TABLE_SIZE)
            break;
    }
    
    printf("Key %d not found, cannot delete!\n", key);
    printf("-------------------------------------\n");
}

// Display hash table
void display()
{
    printf("Hash Table:\n");
    printf("Index\tValue\n");
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i] == -1)
            printf("%d\t(empty)\n", i);
        else if(hashTable[i] == -2)
            printf("%d\t(deleted)\n", i);
        else
            printf("%d\t%d\n", i, hashTable[i]);
    }
    printf("-------------------------------------\n");
}

int main()
{
    int choice, key;
    
    initHashTable();
    
    do
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("-------------------------------------\n");
        
        switch(choice)
        {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
                
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
                
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice!\n");
                printf("-------------------------------------\n");
        }
    } while(choice != 5);
    
    return 0;
}