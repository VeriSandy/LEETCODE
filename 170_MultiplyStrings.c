/*
Idea
Use similar concept as multiplication
Multiply num1 with first character(from right) of num2, keep it in buffer
Multiply num1 with second character(from right) of num2, add this with the old data in buffer with this new data.
*/

char * multiply(char * num1, char * num2)
{
    if(*num1=='0' || *num2=='0') return "0";
    
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    
    char *out = malloc(l1+l2+1);
    memset(out, 0x00, l1+l2+1);
    int outlen = l1+l2+1;
    
    if(l1 == 0 && l2 == 0) return num1;
    
    else if(l1 == 0)
    {
        l2--;
        while(l2 >= 0)
        {
            out[l2] = '0';
            l2--;
        }
        l2++;
        l2++;
        return &out[l2];
    }
    
    else if(l2 == 0)
    {
        l1--;
        while(l1 >= 0)
        {
            out[l1] = '0';
            l1--;
        }
        l1++;
        l1++;
        return &out[l1];
    }
    
    char *tempBuff = malloc(l1+1);
    memset(tempBuff, 0x00, l1+1);
    
    int templen = l1+1;
    
    l1--;
    l2--;
    outlen--;
    templen--;
    
    int i = 0, j = 0, k = 0, count = 0;
    int p = 0;
    
    int temp = 0, carry = 0;
    
    while(l2 >= 0)
    {
        j = l1;
        k = templen;
        carry = 0;
        temp = 0;
        memset(tempBuff, 0, templen+1);
        
        while(j >= 0)
        {
            temp = (num1[j] - '0')*(num2[l2] - '0') + carry;
            carry = temp/10;
            temp = temp%10;
            tempBuff[k] = temp + '0';
            j--;
            k--;
        }
        if(carry)
            tempBuff[k] = carry + '0';
        else
            k++;

        i = templen;
        p = outlen - count;
        temp = 0;
        carry = 0;
        while(i >= k)
        {
            temp = (out[p]?(out[p]-'0'):0) + tempBuff[i] - '0' + carry;
            carry = temp/10;
            temp = temp%10;
            out[p] = temp + '0';
            
            i--;
            p--;
        }
        
        if(carry)
            out[p] = carry + '0';
        else
            p++;
        
        count++;
        l2--;
    }
    
    i = 0;
    while(p+i <= outlen)
    {
        out[i] = out[p+i];
        i++;
    }
    out[i] = '\0';
    return out;
}
