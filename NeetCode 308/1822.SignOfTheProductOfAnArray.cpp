class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        //we cannot have a running product count because we will run into an overflow error,    
        //instead we can count the negative values in nums

        int negativeCount = 0;

        for(int i = 0; i < nums.size(); i++){

            //anything multiplied by 0 will end up being 0
            if(nums[i] == 0){
                return 0;
            }


            //count negative values
            if(nums[i] < 0) {
                negativeCount++;
            }
        }

        //even negative = positive product = return 1
        //odd negative  = negative product = return -1
        return (negativeCount % 2 == 0) ? 1 : -1;
        
    }
};
