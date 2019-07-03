
/*
Word Ladder - 
Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:
1. Only one letter can be changed at a time.
2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

IDEA --
//USE BFS for shortest path.
//adjacent words are which have only one letter change
//push word to queue if it is adjacent, along with increased distance from the current popped queue element.

*/
typedef struct
{   
    int d;
    char *str;
}ELE;

typedef struct node
{   
    ELE item;
    struct node *next;
}NODE;

typedef struct list
{   
    char *str;
    struct list *next;
}LIST;

typedef struct
{   
    NODE *front, *rear;
}QUE;

QUE *CreateQueue()
{   
    QUE *q = malloc(sizeof(QUE));
    q->front = q->rear = NULL;
    return q;
}

void EnQueue(QUE *q, ELE item)
{   
    NODE *n = malloc(sizeof(NODE));
    //strcpy(n->str, data);
    n->item = item;
    n->next = NULL;
    if(!q->front)
    {   
        q->front = n;
    }
    else
        q->rear->next = n;
    q->rear = n;

    return;
}

ELE DeQueue(QUE *q)
{
    ELE item = {0, ""};
    if(q->front == NULL) return item;
    NODE *n = q->front;
    item = n->item;
    q->front = q->front->next;
    if(!q->front)
        q->rear = NULL;

    return item;
}

void AddNode(LIST **head, char *key)
{
    LIST *n = malloc(sizeof(LIST));
    n->next = *head;
    n->str = key;
    *head = n;
    return;
}

int isAdjacent(char *a, char *b)
{
    int count = 0;
    int l = strlen(a);
    int i = 0;

    for(i = 0; i < l ; i++)
    {
        if(a[i] != b[i])
            count++;

        if(count > 1) return 0;
    }

    return (count == 1)?1:0;
}

void Delete(LIST **head, LIST *temp)
{
    if(*head == NULL) return;

    LIST *cur = *head;
    LIST *prev = NULL;

    if(temp == cur)
    {
        *head = cur->next;
        //free(cur);
        //cur = NULL;
        return;
    }

    while(cur && cur != temp)
    {
        prev = cur;
        cur = cur->next;
    }

    if(cur != NULL)
    {
        //printf("d,asn\n");
        prev->next = cur->next;
        //free(cur);
        //cur = NULL;
    }
    return;
}

int shortestChainLen(char *start, char *end, LIST **head)
{
    QUE *q = CreateQueue();
    ELE item = {1, start};
    EnQueue(q, item);

    //LIST *temp = *head;
    while(q->front)
    {
        ELE cur = DeQueue(q);
        LIST *temp = *head;
        
        while(temp)
        {
            if(isAdjacent(cur.str, temp->str))
            {
                //printf("%s\n", temp->str);
                item.str = temp->str;
                item.d = cur.d + 1;
                EnQueue(q, item);
                
                Delete(head, temp);
                
                if(!strcmp(item.str, end))
                    return item.d;
            }
            temp = temp->next;
        }
    }
    return 0;
}

void PrintList(LIST *t)
{
    while(t)
    {
        printf("%s ", t->str);
        t = t->next;
    }
    printf("\n");
}

int ladderLength(char * beginWord, char * endWord, 
                 char ** wordList, int wordListSize)
{
    LIST *t = NULL;
    
    int i = 0;
    for(i = 0; i < wordListSize; i++)
        AddNode(&t, wordList[i]);

    //PrintList(t); 
    
    return shortestChainLen(beginWord, endWord, &t);
    
    //return 0;
}


