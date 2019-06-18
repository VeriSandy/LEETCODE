
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Input: "MCMXCIV"
Output: 1994

*/

int romanToInt(char * s){
    
    int l = strlen(s);
    
    if(l == 0) return 0;
    
    int i = 0;
    int sum = 0;
    
    while(i < l)
    {
         switch(s[i])
         {
             case 'I':
                 if(s[i+1] &&  (s[i+1] == 'V' || s[i+1] == 'X'))
                 {
                    if(s[i+1] == 'V')
                        sum += 4;
                     if(s[i+1] == 'X')
                        sum += 9;
                     i++;
                 }
                 else
                     sum ++;
                 break;
             case 'V':
                 sum += 5;
                 break;
             case 'X':
                 if(s[i+1] && (s[i+1] == 'L' || s[i+1] == 'C'))
                 {
                    if(s[i+1] == 'L')
                        sum += 40;
                     if(s[i+1] == 'C')
                        sum += 90;
                     i++;
                 }
                 else
                    sum += 10;
                 break;
            case 'L':
                 sum += 50;
                 break;
            case 'C':
                 if(s[i+1] &&  (s[i+1] == 'D' || s[i+1] == 'M'))
                 {
                    if(s[i+1] == 'D')
                        sum += 400;
                     if(s[i+1] == 'M')
                        sum += 900;
                     i++;
                 }
                 else
                    sum += 100;
                 break;     
            case 'D':
                 sum += 500;
                 break;    
            case 'M':
                 sum += 1000;
                 break;
         }
        i++;
    }
  
    return sum;
}


