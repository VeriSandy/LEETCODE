/*
Flatten Nested List Iterator
*/

class NestedIterator(object):
    
    def flatten(self, nestedList):
        if not nestedList:
            return
        for item in nestedList:
            if(item.isInteger() == True):
                self.l.append(item.getInteger())
            else:
                self.flatten(item.getList())
    
    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        
        self.l = []
        self.itr = 0
        self.flatten(nestedList)
        self.len = len(self.l)

    def next(self):
        """
        :rtype: int
        """
        val = self.l[self.itr]
        self.itr += 1
        return val

    def hasNext(self):
        """
        :rtype: bool
        """
        if(self.itr < self.len):
            return True
        return False
        
