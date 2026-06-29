import string


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.translate(s.maketrans("", "", string.punctuation)).lower()
        s = s.translate(s.maketrans("", "", string.whitespace))
        return s == s[::-1]
