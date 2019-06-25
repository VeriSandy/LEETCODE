
//using recursion
void Combination(char * digits, char *s, int m, int n, char hash[m][n], int l, int h, char **a, int *count)
{
    if(l == h)
    {
        s[h] = '\0';
        //printf("%s\n", s);
        strcpy(a[*count], s);
        *count = *count +1;
        return;
    }
    
    int i = 0, j = 0;
    
    for(i = l; i < h; i++)
    {
        j = 0;
        //printf("l = %d\n", l);
        while(l < h && hash[digits[i] - '0'][j])
        {
            s[l] = hash[digits[i] - '0'][j];
            s[l+1] = '\0';
            //printf("%c %d\n", s[l], l);
            Combination(digits, s, m, n, hash, l+1, h, a, count);
            j++;
        }
        l = h;
    }
}

char ** letterCombinations(char * digits, int* returnSize){

    char hash[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    
    int l = strlen(digits);
    *returnSize = 0;
    
    if(l == 0) return NULL;
    
    
    int total = 1;
    int i = 0;
    
    for(i = 0; i < l; i++)
        total *= strlen(hash[digits[i] - '0']);
    
    char **a = malloc(sizeof(char *)*total);
    
    char *s = malloc(l+1);
    
    for(i = 0; i < total; i++)
        a[i] = malloc(l+1);
    
    int count= 0;
    
    Combination(digits, s, 10, 5, hash, 0, l, a, &count);
    
     //printf("%d %s %d\n", digits[0] - '0', hash[digits[0] - '0'], l);
    
    printf("%d\n", count);
    
    
*returnSize =  total;
    
    return a;
}

====================
//using queue
class Solution:
    
    def letterCombinationsUtil(self, digits, l, table):
        list1 = []
        if(l == 0):
            return list1
        q = collections.deque()       
        q.append("")        
        while(len(q)):
            s = q.pop()

            if(len(s) == l):
                list1.append(s)

            if(len(s) < l):
                for i in table[digits[len(s)]]:
                    q.append(s+i)
            
        return list1
    
    def letterCombinations(self, digits: str) -> List[str]:
        
        table = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        
        l = len(digits)
        
        l1 = []
        for i in digits:
            l1.append(int(i))     
        list1 = self.letterCombinationsUtil(l1, l, table)
            
        return list1
        
        
        
        
