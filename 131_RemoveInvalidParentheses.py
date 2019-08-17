'''
#Remove Invalid Parentheses
We need to check all the strings so use BackTrack
'''
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        
        def IsParentheses(c):
            return (c == '(' or c == ')')
        
        #check string, if it is  valid
        def IsValidParentheses(s1):
            cnt = 0
            for c in s1:
                if(c == '('):
                    cnt += 1
                elif(c == ')'):
                    cnt -= 1
                
                if(cnt < 0):
                    return False
            
            return (cnt == 0)
        
        '''
        main logic to remove invalid Parentheses
        ''' 
        _res  = []
        q =  []
        visit = set()
        q.append(s)
        visit.add(s)
        level = False #Once you get the result at any level, only of that level strings should be processed further, so we have minimum removal. Else below logic removes all the parentheses one by one.
        
        while(len(q)):
            temp = q.pop(0)
            if(IsValidParentheses(temp)):
                #print("result: " + temp)
                _res.append(temp)
                level = True
            
            if(level == True):
                continue
                
            k = 0
            for ch in temp:
                if(IsParentheses(ch) == False):
                    k += 1
                    continue
                
                temp1 = temp[0:k] + temp[k+1:]
                if(temp1 not in visit):
                    #print(temp1)
                    q.append(temp1)
                    visit.add(temp1)
                    
                k += 1
        
        return _res
                
                
