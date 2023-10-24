class Solution {
public:

/*
  Problem:
      You are given two 0-indexed integer permutations A and B of length n.
      A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
      Return the prefix common array of A and B.
      A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

*/
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> res (n, 0);
        unordered_map<int, int> map;
        int count = 0;

        // store numbers in A into a hashMap
        for(int i = 0 ; i < n; i++) {

            map[A[i]] = 1;
            count = 0;

            // go through b up until the current index to see how many numbers are in both arrays
            for(int j = 0; j <= i; j++) {
                if(map.count(B[j])) count++; 
            }

            // set res[i] to however many numbers in both arrays found
            res[i] = count; 
        }

        return res;
        
    }
};
