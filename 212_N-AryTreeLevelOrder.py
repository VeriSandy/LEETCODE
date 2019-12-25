'''
N-ary Tree Level Order Traversal
Use queue to keep the numbers at one level.
Similar to Level order traversal for Binary tree
'''

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        
        l = []
        
        if root == None:
            return l
        
        q = []
        l1 = []
        q.append(root)
        q.append(None)
        
        while(len(q)):
            temp = q.pop(0)
            if temp == None:
                
                q1 = []
                while(len(l1)):
                    q1.append(l1.pop(0))
                l.append(q1)
                if(len(q)):
                    q.append(None)
            else:
                print(temp.val)
                l1.append(temp.val)
                for x in temp.children:
                    q.append(x)
        
        return l
