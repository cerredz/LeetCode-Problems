class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:

        '''
          # used python to get around the memory allocation limit for a long long in c++ (8 bytes)
          Problem:
            You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.
            Return the string that represents the kth largest integer in nums.
            Note: Duplicate numbers should be counted distinctly. For example, 
            if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.
        '''
        # insert all of the numbers in nums into a max heap
        max_heap = []
        for s in nums:
            heapq.heappush(max_heap, -int(s))

        # max heap already sorted in descending order, pop from it k - 1 times
        while k > 1:
            heapq.heappop(max_heap)
            k -= 1
            
        # return kth greatest number
        return str(-max_heap[0])
