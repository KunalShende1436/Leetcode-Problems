class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        brackets={
            '}' : '{',
            ')' : '(',
            ']' : '[',
        }
        for x in s:
            if x in brackets :
                if stack and stack[-1] == brackets[x]:
                    stack.pop()
                else :
                    return False    
            else:
                stack.append(x)


        return len(stack) == 0


        