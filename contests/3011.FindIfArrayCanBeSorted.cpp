class Solution {
public:
/*
  Problem:
    You are given a 0-indexed array of positive integers nums.
    In one operation, you can swap any two adjacent elements if they have the same number of set bits. You are allowed to do this operation 
    any number of times (including zero). Return true if you can sort the array, else return false.

*/
    int getSetBits(int num) {
        int res = 0;
        while(num > 0){
            res += num & 1;
            num >>= 1;
        }
        return res;
    }
    
    bool canSortArray(vector<int>& nums) {
        
        bool isSorted = true;
        int n = nums.size();
        
        vector<int> set_bits(n, 0);
        for(int i = 0; i < n; i++){
            set_bits[i] = getSetBits(nums[i]);
        }
        
        
        for (int i = 0; i < n - 1; i++) {
            bool isSame = true;
            for (int j = i + 1; j < n; j++) {
                if(set_bits[j] != set_bits[i]) isSame = false;
                if (isSame && set_bits[i] == set_bits[j] && nums[j] < nums[i]) {
                    swap(nums[i], nums[j]);
                }
            }
        }

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                return false;
            }
        }

        
    
        
        return true;
    }
};
