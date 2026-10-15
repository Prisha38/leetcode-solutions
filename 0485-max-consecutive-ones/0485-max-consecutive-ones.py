

class Solution:
    def findMaxConsecutiveOnes(self, a: List[int]) -> int:
        return max(accumulate(a,lambda q,v:q*v+v))
        