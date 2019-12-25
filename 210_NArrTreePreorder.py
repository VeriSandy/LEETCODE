'''
1. Recursive approach.

2. Iterative approach.
    Push root value first, then its children from left to right.
    Use combination of stack and queue.
'''
#Recursive approach.

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        l = []
                
        if root == None:
            return l
        
        l.append(root.val)
        
        for x in root.children:
            temp = self.preorder(x)
            for i in temp:
                l.append(i)
            
        return l


#Iterative approach.
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        
        l = [] #list to be returned
                
        if root == None:
            return l
        
        stack = [] #use this as stack
        temp = []#this is temporary queue.
        
        stack.append(root)
        
        while(len(stack)):
            node = stack.pop()#this will pop last item
            l.append(node.val)
            
            for x in node.children:
                temp.append(x)
            
            while(len(temp)):
                stack.append(temp.pop())
            
        return l
    
    
