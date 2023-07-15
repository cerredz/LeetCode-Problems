class Solution {
public:

/*

    Problem:
        You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] 
        represents the strength of the jth potion. You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths 
        is at least success. Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

    Approach:
        1. Notice that the order of spells matter, but the order of potions do not. For this reason we can 
            sort potions in the very beginning in order to perform a binary search for this algorithmn
        2. Once we sort potions, we can run a binary search for every index in spells, this reduces the running time
            of our algorithm from 0(n^2) to 0(n log n) and can be performed in a separate function, 
            our lower bound will be spells[i] (where i is the current index in our iteration of spells) * potions[0], 
            and our upper bound will be spells[i] * value of last element in potions
        3. Perform a modified binary search by checking if the mid element * spells[i] is >, <, or = success,
            if it is greater than or equal to then move the right pointer to the left, else move the left pointer
            to the right
        4. At the end of the binary search, return however many indexes are from right -> potions.size(), as this
            will be how many number are >= success
        5. Continue steps 2-4 for everey element in spells, and add the returned value for the back of the res vector
*/  

    //create a helper function to perform binary search
    int numPairs(long long spell, vector<int>&potions, long long success) {

        //declare pointers
        int left = 0, right = potions.size() - 1;


        //perform modified binary search
        while(left <= right) {

            int mid = (left + right) / 2;
            
            //compare spell * potions[mid] to success
            if(spell * potions[mid] >= success) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        //number to the left of right will be lower than success
        return potions.size() - right - 1;

    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> res;

        //order of potions does not matter, sort it so we can perform a binary search
        sort(potions.begin(), potions.end());

        //perform a binary search at every index in spells
        for(int i = 0; i < spells.size(); i++) {

            //add returned value to the back of res
            res.emplace_back(numPairs(spells[i], potions, success));
        }

        return res;



    }
};
