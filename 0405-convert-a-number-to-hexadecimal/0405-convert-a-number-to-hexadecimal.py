class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"

        digits ="0123456789abcdef"

        if num < 0:
            num +=2**32

        ans = ""

        while num > 0:
            rem = num % 16
            ans = digits[rem] + ans
            num //= 16

        return ans            
        