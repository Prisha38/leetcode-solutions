class Solution:
    def findKthPositive(self, arr: list[int], k: int) -> int:
        arr_set = set(arr)
        current = 1
        missing_count = 0
        while missing_count < k:
            if current not in arr_set:
                missing_count+=1
            current+=1
        return current -1

        