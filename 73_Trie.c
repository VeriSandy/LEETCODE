/*
  Implement Trie (Prefix Tree)
*/

#define SIZE 26

typedef struct trie{
    struct trie *child[SIZE];
    bool EndOfWord;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate(){
    Trie *node = malloc(sizeof(Trie));
    if(node)
    {
        int i = 0;
        node->EndOfWord = false;

        for(i = 0; i < SIZE; i++)
            node->child[i] = NULL;
    }
    return node;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int i = 0;
    int index = 0;
    int l = strlen(word);
    Trie *pCrawl = obj;

    for(i = 0;i < l ; i++)
    {
        index = word[i] - 'a';
        if(!pCrawl->child[index])
            pCrawl->child[index] = trieCreate();
        pCrawl = pCrawl->child[index];
    }
    pCrawl->EndOfWord = true;
    return;
    
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    int i = 0, l = strlen(word);
    int index = 0;
    Trie *pCrawl = obj;
    for(i = 0; i < l ; i++)
    {
        index = word[i] - 'a';
        if(!pCrawl->child[index])
            return false;
        pCrawl = pCrawl->child[index];
    }
    return (pCrawl && pCrawl->EndOfWord);
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    int i = 0, l = strlen(prefix);
    int index = 0;
    Trie *pCrawl = obj;
 
    for(i = 0; i < l ; i++)
    {
        index = prefix[i] - 'a';
        if(!pCrawl->child[index])
            return false;
        pCrawl = pCrawl->child[index];
    }
    return true;
}

void trieFree(Trie* obj) {
    int i = 0;
    
    for(i = 0; i < SIZE ; i++)
    {
        if(obj->child[i])
           trieFree(obj->child[i]);
    }
    free(obj);
    obj = NULL;
}
