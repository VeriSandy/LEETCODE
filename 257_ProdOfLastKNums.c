typedef struct
{
    int *arr;
    int count;
}ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() 
{
    ProductOfNumbers *p = malloc(sizeof(ProductOfNumbers));
    p->arr = malloc(sizeof(int)*40000);
    p->count = -1;
    return p;
}

void productOfNumbersAdd(ProductOfNumbers *obj, int num)
{
    obj->count++;
    obj->arr[obj->count] = num;
    return;
}

int productOfNumbersGetProduct(ProductOfNumbers *obj, int k)
{
    int data = 1, i = 0;
    while(i < k)
    {
        data *= obj->arr[obj->count - i];
        i++;
    }
    
    return data;
}

void productOfNumbersFree(ProductOfNumbers* obj)
{
    free(obj->arr);
    obj->arr = NULL;
    free(obj);
    obj = NULL;
    return;
}
