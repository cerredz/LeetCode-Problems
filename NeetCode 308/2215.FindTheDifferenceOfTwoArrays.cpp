class Solution {
public:
/*
---------------------------------------------------------------------------------------------------------------------------------
    Problem:
        Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where: 
        answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
        answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
        Note that the integers in the lists may be returned in any order.
---------------------------------------------------------------------------------------------------------------------------------
*/
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        

        vector<vector<int>> res;

        //store whether or not we find a number in a hashMap
        unordered_map<int,int> num1Freq;
        unordered_map<int,int> num2Freq;

        for(int i : nums1) {
            num1Freq[i] = 1;
        }

        for(int i : nums2) {
            num2Freq[i] = 1;
        }

        //create the first row in res
        vector<int> temp;
        for(auto entry : num1Freq) {

            //if num in num1 and not in num2
            if(!num2Freq.count(entry.first)){
                temp.push_back(entry.first);
            }
        }

        res.push_back(temp);
        temp.clear();
        
        //create the second row in res
        for(auto entry : num2Freq){

            //if num in num2 and not in num1
            if(!num1Freq.count(entry.first)){
                temp.push_back(entry.first);
            }
        }

        res.push_back(temp);
        return res;

    }
};
