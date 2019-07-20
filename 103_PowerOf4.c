//If power of 4, count of set bits should be only 1 
//but number of zeros before set bit should be even.

bool isPowerOfFour(int n){
    
    if(n == 1) return true;
    
    if(n < 4) return false;    

    int pos = log2(n);
    
    printf("%d", pos);
    
    n = n &(n-1);

    return n == 0 && pos%2 == 0;    
}

