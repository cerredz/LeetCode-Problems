class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        vector<vector<int>> res;
        unordered_set<int> set;
        
        int numsMoved = 0;
        //we will be adding all elements to a set after every iteration, and adding that set to res after every sweep of the for loop
        while(numsMoved != nums.size()) {
            
            vector<int> temp;
            
            for(int i = 0; i < nums.size();i++) {
                
                //if we have not seen current number
                if(nums[i] > 0) {
                    
                    //if number is not already in the set 
                    if(!set.count(nums[i])){
                        set.insert(nums[i]);
                        temp.emplace_back(nums[i]);
                        nums[i] = -1;//set nums[i] to -1 to simulate a deletion without actually deleting
                        numsMoved++;
                    }
                }
            }
            //temp will have same element of the set
            res.emplace_back(temp);
            //make sure to clear set
            set.clear();
            
        }
        return res;
    }
};
