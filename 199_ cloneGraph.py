'''
Use BFS approach
Keep visiting and creating new nodes.

Have a map, to see if node is visited.
If not visited, add this and correspoding new created node to map.
and update the neighbors of node.
If already visited just then just udate the neighbors of node.

'''

from collections import deque
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        q = deque([node])
        mapping ={node : Node(node.val,[])}
        
        while q:
            n =q.popleft()
            for i in n.neighbors:
                if i not in mapping:
                    q.append(i)
                    mapping[i] = Node(i.val, [])
                mapping[n].neighbors.append(mapping[i])
        return mapping[node]
