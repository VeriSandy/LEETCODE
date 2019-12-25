'''
1. Recursive approach.

2. Iterative approach.
   Use two stack approach
   Push root to first stack.
   Keep looping while first stack is not empty.
   pop first stack, push children of popped node to first stack.
   Push popped node to second stack.
'''


# Recursive approach

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        
        l = []
        
        if(root == None):
            return l
        
        for x in root.children:
            temp = self.postorder(x)
            for i in temp:
                l.append(i)
        
        l.append(root.val)
        
        return l

# Iterative approach 
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        
        l = []
        
        if(root == None):
            return l
        
        
        stack = [] #use this as stack
        temp = []#this is temporary queue.
        
        stack.append(root)
        
        while(len(stack)):
            node = stack.pop()#this will pop last item
            
            for x in node.children:
                stack.append(x)
                
            temp.append(node.val)
            
        
        while(len(temp)):
            l.append(temp.pop())   
        
        return l
        
        
        #temp.reverse()
        #return temp
        
        #return temp[::-1]
