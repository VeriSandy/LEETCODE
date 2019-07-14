'''
4 sum
Given four lists A, B, C, D of integer values, 
compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.


1. Naive -- take 4 loops and do. O(n4)
at most you can make O(n3), using hashing in last array or sorting

2. Take each pair of last two arrays, keep it in hash table. - O(n2)
Take each pair of first two arrays and see if required sum exist in hash table. - O(n2)
'''
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        MyHash = {}
        for i in C:
            for j in D:
                key = i+j
                if not key in MyHash:
                    MyHash[key] = 1
                else:
                    MyHash[key] += 1
                
        count = 0
        for i in A:
            for j in B:
                s = i+j
                if -s in MyHash:
                    count += MyHash[-s]
                    
        return count
            
            
            
            
            
           
