class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        
        int totalSum = 0, leftSum = 0;
        vector<int> res;
        //will use totalSum for computing rightSum
        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }
        
        
        totalSum -= nums[0];
        res.emplace_back(totalSum);
        
        for(int i = 1; i < nums.size(); i++) {
            //compute leftSum at i
            leftSum += nums[i - 1];
            //totalSum - nums[i] will give you the rightSum
            totalSum -= nums[i];
            //compute absolute value of rightSum - leftSum
            res.emplace_back(abs(totalSum - leftSum));
        }
        
    
        return res;
    }
};
