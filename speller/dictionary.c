// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 52;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashN = hash(word);

    if (table[hashN] == NULL)
    {
        return false;
    }

    node *temp = table[hashN];
    if (strcmp(temp->word, word) == 0)
    {
        return true;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (strcmp(temp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += word[i];
    }
    sum %= 52;
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    //char *word = malloc(LENGTH + 1); //might have to allocate memory
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF) //might have to reset word array
    {
        int hashN = hash(word);

        if (table[hashN] == NULL)
        {
            node *pWord = malloc(sizeof(node));
            strcpy(pWord->word, word);
            pWord->next = NULL;
            table[hashN] = pWord;
            free(pWord);
            continue;
        }

        node *pWord = malloc(sizeof(node));
        strcpy(pWord->word, word);
        pWord->next = table[hashN];
        table[hashN] = pWord;
        free(pWord);
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
