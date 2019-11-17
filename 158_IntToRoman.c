
/*
Ideas ----

1. Number can be > 1000.
2. Number can be >= 900 and < 1000.
3. Number can be >= 500 and < 900.
4. Number can be >= 400 and < 500.

*/
char * intToRoman(int num)
{
    char *buff = malloc(16);
    memset(buff, 0, 16);
    int i = 12, div = 0;
    int a[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    char sym[][3] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 

    while(num)
    {
        div = num/a[i];
        num = num%a[i];
        
        while(div)
        {
            strcat(buff, sym[i]);
            div--;
        }
        i--;
    }
    return buff;
}


================================================================================
char * intToRoman(int num)
{
    int temp = num;
    char *buff = malloc(16);
    int ibuff= 0;
    
    while(num)
    {
        if(num >= 1000)
        {
            buff[ibuff++] = 'M';
            num -= 1000;
        }
        else if(num >= 900)
        {
            buff[ibuff++] = 'C';
            buff[ibuff++] = 'M';
            num -= 900;
        }
        else if(num >= 500)
        {
            buff[ibuff++] = 'D';
            num -= 500;
        }
        else if(num >= 400)
        {
            buff[ibuff++] = 'C';
            buff[ibuff++] = 'D';
            num -= 400;
        }
        else if(num >= 100)
        {
            buff[ibuff++] = 'C';
            num -= 100;
        }
        else if(num >= 90)
        {
            buff[ibuff++] = 'X';
            buff[ibuff++] = 'C';
            num -= 90;
        }
        else if(num >= 50)
        {
            buff[ibuff++] = 'L';
            num -= 50;
        }
        else if(num >= 40)
        {
            buff[ibuff++] = 'X';
            buff[ibuff++] = 'L';
            num -= 40;
        }
        else if(num >= 10)
        {
            buff[ibuff++] = 'X';
            num -= 10;
        }
        else if(num >= 9)
        {
            buff[ibuff++] = 'I';
            buff[ibuff++] = 'X';
            num -= 9;
        }
        else if(num >= 5)
        {
            buff[ibuff++] = 'V';
            num -= 5;
        }
        else if(num >= 4)
        {
            buff[ibuff++] = 'I';
            buff[ibuff++] = 'V';
            num -= 4;
        }
        else if(num >= 1)
        {
            buff[ibuff++] = 'I';
            num -= 1;
        }
    }
    buff[ibuff] = '\0';
    
    return buff;
}
