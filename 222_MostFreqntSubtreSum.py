'''
Take Sum at each node, put it in HashMap. 
Increase the HashMap count if Sum is same as any existing Sum.
Return the ones, has maximum frequency
'''

class Solution:
    def findFrequentTreeSumUtil(self,root, Map):
        if(root == None):
            return 0
        if(root.left == None and root.right == None):
            if root.val in Map:
                key = Map[root.val]
                key += 1
                Map[root.val] = key
            else:
                Map[root.val] = 1
            #print(root.val)
            
            return root.val
        
        Sum1 = self.findFrequentTreeSumUtil(root.left, Map)
        Sum2 = self.findFrequentTreeSumUtil(root.right, Map)        
        Total = Sum1 + Sum2 + root.val 
        
        if Total in Map:
            key = Map[Total]
            key += 1
            Map[Total] = key
        else:
            Map[Total] = 1
        
        #print(Total)
        return Total
    
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        
        Map = {}
        MaxCount = 0
        self.findFrequentTreeSumUtil(root, Map)
        
        for val in Map.values():
            if(val > MaxCount):
                MaxCount = val        
        
        result = []
        
        for key, val in Map.items():
            if(val == MaxCount):
                result.append(key)
        
        return result
            
            
       
