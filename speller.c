//implement a dictionary`s functionality

#include <ctype.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<strings.h>
#include<dictionary.h>



//represent a node in a hash table
typedef struct node
{
    char word[LENGHT + 1];
    struct node *next;
}node;

//TODO: choose a number of buckets in hash table
count unsigned int N = 26;

//hash table
unsigned int word_count;
unsigned int hash_value;


//returns true if word in dictionary, else false
bool check (const char *word)
{
   //TODO
   hash_value = hash(word);
   node *cursor = table[hash_value];

   //go through linked list
   while(cursor != 0)
   {
       if(strcasecmp(word, cursor->word)== 0)
       {
           return true;
       }
       cursor = cursor->next;
   }
   return false;
}

//hashs word to a number
unsigned int hash (const char *word)
{
    //TODO: improve this hash function
    unsigned long total = 0;
    for (int i = 0; i< strlen (word); i++)
    {
        total +=tolower(word[i]);
    }
    return total % N;
    }
}
//loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //TODO
    //open dictionary
    FILE *file = fopen(dictionary, "r");

    //return NULL if file cannot be opened
    if(file == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }
    //declare variable called word
    char word[LENGTH + 1];

    //scan dictionary for strings up until EOF
    while (fscanf(file, "%s", word) != EOF)
    {
        //Allocate memory for new node
        node *n = malloc(sizeof(node));

        //if malloc returns NULL, return false
        if (n == NULL)
        {
            return false;
        }

        //copy word into node
        strcpy(n->word, word);
        hash_value = hash(word);
        n-> next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(file)
}

//returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //TODO
    return 0;
}

//unload dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //TODO
    for (int i = 0; i < N;)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *tmp = cursor;
            cursor->next;
            free(temp);
        }
        if (cursor == NULL)
        {
            return true;
        }
    }
    return false;
}