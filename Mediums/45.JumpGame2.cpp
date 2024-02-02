class Solution {
public:
  /*
    Problem:
      You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
      Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
      0 <= j <= nums[i] and i + j < n Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

*/
    
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int max_reach = 0;
        int prev_max = 0;
        int jumps = 0;

        if(n <= 1) return 0; // edge case

        for(int i = 0; i < n - 1; i++) {
            max_reach = max(max_reach, i + nums[i]); // simulates a jump 
            if(i == prev_max) {
                // we have reached the previous jump's max index, we now need to update the max index we can jump to
                prev_max = max_reach;
                jumps++;
            }
        }

        return jumps;

    }
};
