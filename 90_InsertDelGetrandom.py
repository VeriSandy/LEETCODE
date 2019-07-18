'''
Insert Delete GetRandom O(1)
Design a data structure that supports all following operations in average O(1) time.
    insert(val): Inserts an item val to the set if not already present.
    remove(val): Removes an item val from the set if present.
    getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.


IDEA - 
1. Take a set and a dictionary, Keep adding. 
For random convert set to list then print the random element.

2. Another way is, have list and keep hash table with address stored. 
Insertion, removal will take only constant time. 

'''

class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.s = set()
        self.d = {}
        self.count = 0
            
    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.d:
            return False
        
        self.s.add(val)
        self.d[val] = self.count
        self.count += 1
        #print(self.l[0])
        return True
        

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val in self.d:
            self.d.pop(val)
            #print(j)
            self.s.remove(val)
            self.count -= 1
            return True
        
        return False

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        rand = random.randrange(0, self.count)
        l = list(self.s)
        #print(rand)
        return l[rand]
        
