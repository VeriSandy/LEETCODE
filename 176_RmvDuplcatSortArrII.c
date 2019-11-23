/*
Use two pointer approach.
Keep increasing i and increase j based on the requirement.
*/

int removeDuplicates(int* a, int numsSize)
{
    if(numsSize <= 2)
        return numsSize;
    int i = 1, j = 1, first = 0;
    
    while(i < numsSize)
    {
        if(a[i] == a[i-1])
        {
            if(!first)
            {
                a[j] = a[i];
                j++;
                first = 1;
            }
        }
        else
        {
            a[j] = a[i];
            first = 0;
            j++;
        }
        i++;
    }
    
    return j;
}
