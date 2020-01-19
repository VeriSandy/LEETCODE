int maximum69Number (int num){

    char buff[8] = {0};
    int i = 0, first = 0;
    int num1 = 0;
    
    sprintf(buff, "%d", num);
    
    while(buff[i])
    {
        if(!first && buff[i] == '6')
        {
            buff[i] = '9';
            first = 1;
        }
        num1 = num1*10 + buff[i] - '0';
        i++;
    }
    
    return num1;
}
