class Solution {
public:

  /*
    Problem:
      The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.
      For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
      Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:
      Each element of nums is in exactly one pair, and The maximum pair sum is minimized.  Return the minimized maximum pair sum after optimally pairing up the elements.
      
*/
    int minPairSum(vector<int>& nums) {
        
        int res = INT_MIN, n = nums.size();
        sort(nums.begin(), nums.end()); // sort numbers in order to minimize the max pair sum

        // use two pointers to find the biggest max pair sum
        for(int i = 0; i < n / 2; i++) {
            int pair_sum = nums[i] + nums[n - 1 - i];
            res = max(res, pair_sum);
        }

        return res;
    }
};
