//Decode String

char * decodeString(char * s)
{
    int l = strlen(s);
    
    if(l == 0) return "";
    
    int st[l];
    int top = -1, count = 0, tempCount = 0, mulPos = 0;;
    memset(st, 0, sizeof(st));
    
    char *temp1 = malloc(l+1);
    memset(temp1, 0, l+1);
    strcpy(temp1, s);
    
    char *temp2 = malloc(l+1);
    memset(temp2, 0, l+1);
    strcpy(temp2,s);

    int i = 0, j = 0, k = 0, mul = 0;
    while(i < l)
    {
        if(temp1[i] == '[')
            st[++top] = i;
        
        else if(temp1[i] == ']')
        {
            k = st[top];
            
            //calculate multiplication factor
            j = k - 1;
            mul = 0;
            mulPos = 0;
            while(j >= 0 && temp1[j] - '0' >= 0 && temp1[j] - '0' <= 9 )
            {
                mul += ((int)pow(10, mulPos))*(temp1[j] - '0');
                j--;
                mulPos++;
            }
            top--;
            
            //length of modified string(only between one pair)
            tempCount = (i - k - 1)*mul;
            
            //total length of new string needed
            count = (k - mulPos) //0 to kth position
                    + tempCount
                    + (l-i -1);//i to last
            
            //change the size of memory, copy array to new string
            temp1 = realloc(temp1, count+1);
            memset(temp1, 0, count+1);
            
            j = 0;
            strncat(temp1, temp2, k-mulPos); //part of the string before this "[ ]" pair
            
            //modified decoded string
            while(j < mul)
            {
                strncat(temp1, &temp2[k+1], (i - k - 1));
                j++;
            }
            
            //last part of the string, after ']' till end.
            strcat(temp1, &temp2[i+1]);
            
            
            temp2 = realloc(temp2, count+1);
            memset(temp2, 0, count+1);
            strcpy(temp2, temp1);
            
            l = strlen(temp1);
            i = (k - mulPos) //0 to kth position
                + tempCount - 1;
            printf("k = %d, mul = %d, tempCount = %d , count = %d, l = %d and temp1 = %s, i = %d\n", 
                   k, mul, tempCount, count, l, temp1, i);
        }
        i++;
    }    
    
    free(temp2);
    temp2 = NULL;
    return temp1;
}

