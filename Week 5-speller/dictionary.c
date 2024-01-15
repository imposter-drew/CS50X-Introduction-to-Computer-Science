// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

int dictwordsum = 0; // dictionary word counter

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1170;

// Hash table
node *table[N]; // creating an array of node pointers of size N called table

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Your implementation of check must be case-insensitive.
    // If foo is in dictionary, then check should return true
    // with foo, foO, fOo, fOO, fOO, Foo, FoO, FOo, and FOO
    // see strcasecmp(string s1, string s2)
    int value = hash(word);

    // iterate through the hash table bucket with the hashed word value and use strcasecmp in each iteration
    if (table[value] == NULL)
    {
        return false;
    }
    else if (table[value]->word[0] == '\0')
    {
        return false;
    }

    for (node *i = table[value]; i->word[0] != '\0'; i = i->next)
    {
        if (strcasecmp(word, i->word) == 0) // compare words
        {
            return true;
        }
        if (i->next == NULL)
        {
            return false;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int value = 0;
    for (int s = 0; word[s] != '\0'; s++) // to calculate the word value
    {
        if (word[s] == 39) // assign value 0 to apostrophe (')
        {
            value = value + 0;
        }
        else // assign a value to every letter starting with a = 1 and z = 26
        {
            value = value + toupper(word[s]) - 64;
        }
    }
    return value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // fopen dictionary it should return a boolean (true if success,false if not)

    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fclose(dict);
        return false;
    }
    else
    {
        // 1-read strings from file
        char buffer[46];   // To preload every string (dictionary word) before adding it to the node
        node *list = NULL; // To keep track of pointer of the hash table head and start iteration
                           // through this. In case of collisions to find the empty *next pointer

        while (fscanf(dict, "%s", buffer) != EOF)
        {
            int wordsum = 0; // to keep track of the sum of the char values of a word
            for (int i = 0; buffer[i] != '\0'; i++)
            {
                if (buffer[i] == 39) // assign value 0 to apostrophe (')
                {
                    wordsum = wordsum + 0;
                }
                else // assign a value to every letter starting with a = 1 and z = 26
                {
                    wordsum = wordsum + toupper(buffer[i]) - 64;
                }
            }
            // Allocate memory for the hash table.
            // table[wordsum] is the bucket index for the dictionary words. indexing depends on the wordsum value
            if (table[wordsum] == NULL)
            {
                table[wordsum] = malloc(sizeof(node));
                if (table[wordsum] == NULL)
                {
                    return false;
                }
                table[wordsum]->next = NULL;
            }
            // 2-create a new node (malloc) for each word in the dictionary (use the same previous loop)
            // check if mallock return null
            node *n = malloc(sizeof(node)); // node to assign the values from buffer to the hash table
            if (n == NULL)
            {
                return false;
            }
            n->next = NULL;
            // 2.1-copy the word into the node using strcpy
            strcpy(n->word, buffer); // pass the value from buffer to the node

            int b = 0;
            while (b != '\0') // clear buffer
            {
                buffer[b] = 0;
                b++;
            }
            // start indexing dictionary
            if (table[wordsum] == NULL) // if index word is empty
            {
                table[wordsum] = n; // pass the value from the node to the table indexed
                list->next = table[wordsum];
                dictwordsum++; // dictionary word counter
            }
            else
            {
                n->next = table[wordsum];
                table[wordsum] = n;
                dictwordsum++;
            }
        }
        fclose(dict);
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictwordsum;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i <= N; i++) // iterate through the array
    {

        if (table[i] != NULL)
        {
            node *track = table[i];
            node *fr = table[i];
            if (track->next == NULL)
            {
                free(track);
            }
            else // iterate through linked list
            {
                while (track->next != NULL)
                {
                    fr = track;
                    track = track->next;
                    free(fr);
                }
                free(track);
            }
        }
    }
    return true;
}
