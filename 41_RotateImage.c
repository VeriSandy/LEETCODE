/*
IDEA - just take one array equal to size of one row
first copy the previuos array
Then while traversing matrix, keep copying from the previous saved data.
Keep this data to new array.

Or other is below 
We need only half cycles to rotate it.
*/
void rotate(int** a, int matrixSize, int* matrixColSize){

    int p = matrixSize;
    int q = *matrixColSize;
    int i = 0;
    int j = 0;

    int temp = 0;

    if(p <= 1 ) return;

    
    for(i = 0; i < p/2; i++)
    {
        for(j = i; j < p - 1 -i ; j++)
        {      
            int temp = a[i][j];
            
            a[i][j] = a[p-j-1][i];
            
            a[p-j-1][i] = a[p-i-1][p-1-j];
            
            a[p-i-1][p-1-j] = a[j][p-1-i];
                
            a[j][p-1-i] = temp;
            
        }
    }
    
    return ;
}

========================
//using four loops
void rotate(int** a, int matrixSize, int* matrixColSize){

    int p = matrixSize;
    int q = *matrixColSize;


    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int count = 0;


    int temp1 = 0;

    if(p <= 1 ) return;

        
    int temp[matrixSize];
    memset(temp, 0, sizeof(temp));

    while(i < p && j < q)
    {

        //copy initial data
        for (k = j, l = p-1; l >= i; l--)
        {
            temp[k] = a[l][j];
            k++;
        }

        for (k = j, l = j; l < q; l++)
        {
            temp1  = a[i][l];
            a[i][l] = temp[k];
            temp[k] = temp1;
            k++;
        }
        i++;

        for (k = i, l = i ; l < p ; l++)
        {
            temp1  = a[l][q-1];
            a[l][q-1] = temp[k];
            temp[k] = temp1;
            k++;
        }
        q--;

        if(i < p)
        {
            for (k = i , l = q-1 ; l >= j ; l--)
            {
                temp1  = a[p-1][l];
                a[p-1][l] = temp[k];
                temp[k] = temp1;
                k++;
            }
            p--;
        }


        if(j < q)
        {
            for (k= i, l = p-1 ; l >= i ; l--)
            {
                temp1  = a[l][j];
                a[l][j] = temp[k];
                temp[k] = temp1;
                k++;
            }
            j++;
        }

    }
    return;

}


