class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        
        Problem:
        
        The frequency of an element is the number of times it occurs in an array.
        You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
        Return the maximum possible frequency of an element after performing at most k operations.
        """

        #sort the list first to gaurentee the numbers next to keep other have the lowest operations needed
        nums.sort()

        #we will have a left pointer, a right pointer, a sum variable, and a maxFreq variabale to keep track of the greatest length our window gets
        left = right = maxFreq = Sum = 0


        while right < len(nums):
            #current sum of the numbers from left -> right
            Sum += nums[right]

            #if the operations needed for expanding our window are too much, we must shrink out window
            while Sum + k < nums[right] * (right - left + 1):
                
                Sum -= nums[left]
                left += 1
            
            #update maxFreq is necessary
            maxFreq = max(maxFreq, right - left + 1)
            right += 1
        
        return maxFreq

