class Solution:

    '''
        Problem:
          Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

        Approach:
            1. inplement an algorithmn that computes all permutations
            2. One way we can modify the algorithm in step 1 is to use a hashmap map to get the count
                of each number in nums
            3. Instead of getting all possible permutations of nums, we are going to get all 
                possible permutations of the map, and use the count of the map to determine whether
                or not to add a number to a perumation
    '''
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        perm = []
        count = {n:0 for n in nums}

        for num in nums:
            count[num] += 1

        def getPermutations():
            # base case
            if(len(perm) == len(nums)):
                res.append(perm.copy())
                return
            
            # get permutations of all the numbers in the map
            for num in count:
                if count[num] > 0:
                    count[num] -= 1
                    perm.append(num)
                    getPermutations()

                    # backtrack
                    count[num] += 1
                    perm.pop()
        

        getPermutations()
        return res




    
