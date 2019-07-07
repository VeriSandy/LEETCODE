

uint32_t reverseBits(uint32_t n)
{ 
    unsigned int temp1 = 1, i, temp = (unsigned int)1 << 31, temp2 = 0;
    
    for (i = 0; i <= 15; i++) 
    { 
        temp1 = (n & ((unsigned int)1 << i))?1:0;
        n = n & ~((unsigned int)1 << i);
        
        temp2 = (n & ((unsigned int)temp >> i))?1:0;
        n = n & ~((unsigned int)temp >> i);
                
        n = n | (temp1 << (31-i)) | (temp2 << i) ;
    }
    
    return n;
}


==============

uint32_t reverseBits(uint32_t n)
{ 
    unsigned int reverse_num = 0, i, temp;
    
    for (i = 0; i < 32; i++) 
    { 
        temp = (n & ((unsigned int)1 << i)); 
        if(temp) 
            reverse_num |= ((unsigned int)1 << (31-i)); 
    } 
   
    return reverse_num; 
}
