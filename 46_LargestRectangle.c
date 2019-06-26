
//use stack
typedef struct
{
    int top;
    int *a;
}Stack;

Stack *CreateStack(int size)
{
    Stack *stk = malloc(sizeof(Stack));
    stk->top = -1;
    stk->a = malloc(sizeof(int)*size);
    
    return stk;
}

void PushStack(Stack *stk, int data)
{
    stk->top++;
    stk->a[stk->top] = data;
}

int PopStack(Stack *stk)
{
    int data = stk->a[stk->top];
    
    stk->top--;
    
    return data;
}

int largestRectangleArea(int* heights, int heightsSize)
{
    if(heightsSize == 0 ) 
        return 0;
    int l = 0, r = heightsSize -1;
    int Max = 0, Area = 0; 
    
    
    Stack *stk = CreateStack(heightsSize);
    
    while(l < heightsSize)
    {
        if(stk->top == -1 || heights[stk->a[stk->top]] <= heights[l])
        {
            PushStack(stk, l);
            l++;
        }   
        else
        {
            int temp = PopStack(stk);
            
            Area = heights[temp] * (stk->top == -1?l:l - stk->a[stk->top] - 1);
            
            if(Max < Area)
                Max = Area;
            
            //printf("%d %d\n", Max, Area);
        }
    }
    
    while(stk->top != -1)
    {
        int temp = PopStack(stk);

        Area = heights[temp] * (stk->top == -1?l:l - stk->a[stk->top] - 1);

        if(Max < Area)
            Max = Area;
    }

    return Max;
}

=================================
//use segment tree, and recursion
/*
We can use Divide and Conquer to solve this in O(nLogn) time. The idea is to find the minimum value in the given array. Once we have index of the minimum value, the max area is maximum of following three values.
a) Maximum area in left side of minimum value (Not including the min value)
b) Maximum area in right side of minimum value (Not including the min value)
c) Number of bars multiplied by minimum value.

*/
int MinVal(int *a, int b , int c)
{
    if(b == -1) return c;
    if(c == -1) return b;
    
    return a[b]>a[c]?c:b;
}

//ss segment start, se segment end, si segment index
int  ConstructST(int *a, int ss, int se, int *st, int si)
{
    //if segment start and end same
    if(ss == se)
    {
        st[si] = ss;
        return st[si];
    }
    
    int mid = (ss+se)/2;
    //set min value to this index, out of right and left subtree
    st[si] = MinVal(a,ConstructST(a,ss,mid,st,2*si+1),ConstructST(a,mid+1,se,st,2*si+2));
    return st[si];
}
//build min range segment tree
int *BuildST(int *a, int n)
{
    int x = (int)ceil(log2(n));   
    int size = (int)pow(2, x+1) - 1; //total size of segment tree
    int *st = malloc(sizeof(int)*size);
    ConstructST(a, 0, n-1, st, 0);
    return st;
}

int Max(int a, int b, int c)
{
    /*
    if(a > b)
    {
        if(c > a) return c;
        return a;
    }
    //b > a
    if(c > b) return c;
    return b;
    */
    //replace above code with the line below
    return a>b?(c>a?c:a):(c>b?c:b);
}


int FindMinUtil(int *a, int *st, int ss, int se, int qs, int qe, int index)
{
    if(ss > qe || se < qs)
        return -1;
    
    //if segment is in between in the query range
    if(qs <= ss && qe >= se)
        return st[index];
    
    int Mid = (ss+se)/2;
    
    return MinVal(a, FindMinUtil(a,st,ss,Mid,qs,qe,2*index+1),
                  FindMinUtil(a, st, Mid +1 , se, qs, qe, 2*index+2));
}


//qs == query start, qer === query end
int FindMin(int *a, int *st, int n, int qs, int qe)
{
    if(qs < 0 || qe > n-1 || qs > qe) return -1;
    
    return FindMinUtil(a, st, 0, n-1, qs, qe, 0);
}

int GetMaxArea(int *a, int *st, int n, int l , int r){
    
    if(l > r) return INT_MIN;
    
    if(l == r) return a[l];
    
    int Min = FindMin(a, st, n, l, r);
    
    return Max(GetMaxArea(a,st,n,l,Min-1), GetMaxArea(a, st, n, Min+1, r), a[Min]*(r-l+1));
}

int largestRectangleArea(int* heights, int heightsSize)
{
    if(heightsSize <= 0) return 0;
    int *st = BuildST(heights, heightsSize);
    return GetMaxArea(heights, st, heightsSize, 0, heightsSize-1);
    return 0;
}                                                                                           
