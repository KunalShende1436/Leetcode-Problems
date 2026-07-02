class Solution:
    def firstUniqChar(self, s: str) -> int:
        for x in range(len(s)):
            if s.count(s[x])==1:
                return x
        
        return -1

        