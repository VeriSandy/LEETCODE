/*
Highest(from sight side) similar bits in both numnbers will not change other bits will keep changing

Or 
Find the highest bit till both numbers has similar bits then return only those many bits as highest(from sight side) similar bits in both numnbers will not change other bits will keep changing

*/
    
int rangeBitwiseAnd(int m, int n)
{
    int HighestSetBit = log2(n), HighestSetBitTemp;   
    int i = HighestSetBit, temp = 0;
    int num = 0;
    
    //highest bit till both numbers has similar bits
    //xor operation will reset the similar bits
    //so finally it will have highest different bit set in XOR.
    temp = m^n;
    if(temp)
        HighestSetBitTemp = log2(temp);
    else
        HighestSetBitTemp = -1;
    
    if(HighestSetBitTemp == HighestSetBit)
    {
        //no higest bits are similar in numbers.
        return 0;
    }
    
    //copy till HighestSetBitTemp+1 from HighestSetBit.
    temp = ((long)1 << (HighestSetBitTemp+1)) - 1;
    //printf("%d\n", temp);
    temp = ~temp;//temp will have all 1s excepty in range[0, HighestSetBitTemp]  
    
    return m&temp;
}


