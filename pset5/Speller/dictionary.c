// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// Declare a word counter
int counter = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Index into hash table and point temp pointer to location
    unsigned int index = hash(word);
    node* ptr = table[index];
    
    // If hash table at index is null, spelling error
    if (ptr == NULL)
    {
       return false;
    }
   
    // If hash table at index is not null, check if spelling is correct
    if (strcasecmp(ptr->word, word) == 0)
    {
       return true;
    }
    // If has table at index is not null, and spelling is not correct, check next node
    else
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
            if(strcasecmp(ptr->word, word) == 0)
            {
                return true;
                break;
            }
        }
        return false;
    }
   
 }

// Hashes word to a number using djb

unsigned int hash(const char *word)
{
    
    // Create a temporary character string 
    char tmp[strlen(word)];
    strcpy(tmp, word);
    
    // Convert string to lowercase
    for (int i = 0; i < strlen(tmp); i++)
    {
        tmp[i] = tolower(tmp[i]);
    }
    
    // Assign a pointer to character string
    char *ptr = tmp;
    
    // Djb2 hash function
    unsigned long hash = 5381;
    int c;

    while ((c = *ptr++) != 0)
    {
        hash = ((hash << 5) + hash) + c;
    }
    

    return (int) (hash % N);

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Open dictionary file
    FILE *src_dict = fopen(dictionary, "r");
    if (src_dict == NULL)
    {
        return false;
    }
    
    //Declare a character array to allow capture dictionary words
    char *dictionary_word = malloc(LENGTH + 1);
    if (dictionary_word == NULL)
    {
        return false;
    }
    
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    
    
    // Collect words from dictionary file until end of file
    while(fscanf(src_dict, "%s", dictionary_word) != EOF)
    {
        // Increment counter for new word added to hash table
        counter++;
        
        // Create a new node to store the current dictionary_word
        node *new_node = malloc(sizeof(node));
        if(new_node == NULL)
        {
            return false;
        }
        
        // Copy dictionary word into node
        strcpy(new_node->word, dictionary_word);
            
        // Hash the word using hash function
        unsigned int index = hash(dictionary_word);
        
        // Link new node to first element in hash table bucke
        new_node->next = table[index];
        table[index] = new_node;
            

        
    }
    // Close dictionary and free temporary dictionary word node
    fclose(src_dict);
    free(dictionary_word);
    
    // Confirm dictionary is loaded
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    node *cursor;
    node *tmp1;
    
    for (int i = 0; i <= N; i++)
    {
        if(table[i] != NULL)
        {
            cursor = table[i];
            tmp1 = table[i];
        
            while (cursor->next != NULL)
            {
                cursor = cursor->next;
                free(tmp1);
                tmp1 = cursor;
            }
        
            free(cursor);

        }
  
        
    }
    
    return true;
}

