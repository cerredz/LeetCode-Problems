class Solution {
public:
    
    
    /*
        Problem:
            You are given a 0-indexed integer array nums of length n.
            A split at an index i where 0 <= i <= n - 2 is called valid if the product of the first i + 1 elements 
            and the product of the remaining elements are coprime.For example, if nums = [2, 3, 3], then a split at the index i = 0 is 
            valid because 2 and 9 are coprime, while a split at the index i = 1 is not valid because 6 and 3 are not coprime. 
            A split at the index i = 2 is not valid because i == n - 1.
            Return the smallest index i at which the array can be split validly or -1 if there is no such split.
            Two values val1 and val2 are coprime if gcd(val1, val2) == 1 where gcd(val1, val2) is the greatest common divisor of val1 and val2.
    */
    
    //method to find GCF between two numbers
    bool hasGCD(int a, int b) {
            if (a < 0 || b < 0) {
                return false;  // GCD is not defined for negative numbers
            }
            if (a == 0 || b == 0) {
                return false;  // GCD of 0 and any non-zero number is not defined
            }
            int gcd = 1;
            for (int i = 1; i <= a && i <= b; ++i) {
                if (a % i == 0 && b % i == 0) {
                    gcd = i;
                }
            }
            return gcd > 1;
    }

    int findValidSplit(vector<int>& nums) {
        //list of prefix products
        vector<long long> prefixProduct(nums.size() - 1, 1);
        
        //list of suffix products
        vector<long long> suffixProduct(nums.size() - 1, 1);
        
        
        prefixProduct[0] = nums[0];
    
        //calculate prefix products
        for(int i = 1; i < nums.size() - 1 ; i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i];
        }
        suffixProduct[nums.size() - 2] = nums[nums.size() - 1];
        
        //calculate suffix products
        for(int i = nums.size() - 2; i > 0; i--) {
            suffixProduct[i - 1] = suffixProduct[i] * nums[i];
        }
        
        
        long long numerator = 0, denominator = 0;
        
    
        for(int i = 0; i < prefixProduct.size(); i++) {
            //bigger number
            numerator = max(prefixProduct[i], suffixProduct[i]);
            
            //smaller number
            denominator = min(prefixProduct[i], suffixProduct[i]);
            
            //return index if the prefix and suffix has a gcf of 1
            if(!hasGCD(numerator, denominator)) {
                return i;
            }
        }
        
        
        //if all numbers in prefix and suffix have GCF's greater than 1, return -1
        return -1;
        
        
        
        
    }
};
