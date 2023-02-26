class Solution(object):
    def divisibilityArray(self, word, m):
        """
        :type word: str
        :type m: int
        :rtype: List[int]
        """
        
        res = []
        number = 0
    
        for i in word:
            #add each letter to number
            number = (number * 10 + int(i)) % m
            #add 1 if remainder is 0, otherwise add a 0
            res.append(int(number == 0))
        
        return res
