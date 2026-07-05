class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False 
        orginal = x
        rev = 0
        while x:
            digit = x % 10
            rev = rev * 10 + digit
            x //= 10
        return orginal == rev
