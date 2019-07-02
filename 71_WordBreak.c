/*
139. Word Break
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

IDEA --
this can be done usin recursion.
and using DP.
*/
//dp
#define ALPHABET_SIZE 26
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    bool isEndOfWord; 
}; 
  
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  malloc(sizeof(struct TrieNode));   
    pNode->isEndOfWord = false; 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
    return pNode; 
} 
  
void insert(struct TrieNode *root, char *key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < strlen(key); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index]; 
    } 
    pCrawl->isEndOfWord = true; 
} 

bool search(struct TrieNode *root, char* key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < strlen(key); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int l = strlen(s);
    if(l == 0) return true;
    
    struct TrieNode *root = getNode(); 
       
    int i = 0, j = 0;
    
    for (i = 0; i < wordDictSize; i++) 
        insert(root, wordDict[i]);

    int d[l+1];
    memset(d, 0x00, sizeof(d));
    
    char temp[l+1];
    memset(temp, 0x00, l+1);
    
    for(i = 1; i <= l; i++)
    {
        memset(temp, 0x00, l+1);
        memcpy(temp, s, i);
        
        if(d[i] == 0 && search(root, temp))
            d[i] = 1;
        
        if(d[i] == 1)
        {
            if(i == l)
                return true;
                           
            for(j = i+1; j <= l; j++)
            {
                memset(temp, 0x00, l+1);
                memcpy(temp, &s[i], (j-i));

                if(d[j] == 0 && search(root, temp))
                    d[j] = 1;
                
                if(j == l && d[j] == 1)
                    return true;
            }
        }
    }
    return false;
}

=========================================================
//Recursion
#define ALPHABET_SIZE 26
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    bool isEndOfWord; 
}; 
  
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  malloc(sizeof(struct TrieNode));   
    pNode->isEndOfWord = false; 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
    return pNode; 
} 
  
void insert(struct TrieNode *root, char *key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < strlen(key); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index]; 
    } 
    pCrawl->isEndOfWord = true; 
} 

bool search(struct TrieNode *root, char* key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < strlen(key); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 


bool wordBreakUtility(struct TrieNode *root, char * s)
{
    int l = strlen(s);
    if(l == 0) return true;
    int i = 0, j = 0;
    
    char temp[l+1];
    memset(temp, 0x00, l+1);
    
    char temp1[l+1];
    memset(temp1, 0x00, l+1);
    
    for(i = 1; i <= l; i++)
    {
        memset(temp, 0x00, l+1);
        strncpy(temp, s, i);
        
        memset(temp1, 0x00, l+1);
        strcpy(temp1, &s[i]);
        
        //printf("%s %s\n", temp, temp1);
        if(search(root, temp) && wordBreakUtility(root, temp1))
            return true;
    }
    return false;
    
}
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    
    int l = strlen(s);
    
    if(l == 0) return true;
    struct TrieNode *root = getNode(); 
    int i = 0;
    for (i = 0; i < wordDictSize; i++) 
        insert(root, wordDict[i]); 
    return wordBreakUtility(root, s);
}
