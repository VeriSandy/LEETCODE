
int CheckLeapYear(int year)
{
    return year/4 - year/100 + year/400;
}

int daysBetweenDates(char * date1, char * date2)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d1[3], d2[3], i = 0;
    
    char *t = strtok(date1, "-");
    while(t)
    {
            if(t)
            d1[i] = atoi(t);
        t = strtok(NULL, "-");

        i++;
    }
    
    i = 0;
    t = strtok(date2, "-");
    while(t)
    {
                if(t)
            d2[i] = atoi(t);
        
        t = strtok(NULL, "-");

        i++;
    }
    
    //printf("%d %d %d %d %d %d\n", d1[0], d1[1], d1[2], d2[0], d2[1], d2[2]);
    
    long n1 = d1[0]*365+d1[2];
    
    i = 0;
    while(i < d1[1] -1)
    {
        n1 += days[i];
        i++;
    }

    if(d1[1] <= 2)
        n1 += CheckLeapYear(d1[0] - 1);
    else
        n1 += CheckLeapYear(d1[0]);
    
    
    long n2 = d2[0]*365+d2[2];
    
    i = 0;
    while(i < d2[1] -1)
    {
        n2 += days[i];
        i++;
    }

    if(d2[1] <= 2)
        n2 += CheckLeapYear(d2[0] - 1);
    else
        n2 += CheckLeapYear(d2[0]);
    
    
    return (n2-n1)>0?(n2-n1):(-(n2-n1));
}


