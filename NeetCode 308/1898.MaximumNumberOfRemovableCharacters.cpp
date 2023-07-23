
class Solution {
public:

/*
    Problem:
      You are given two strings s and p where p is a subsequence of s. You are also given a distinct 0-indexed integer array removable containing a subset of indices of s 
      (s is also 0-indexed). You want to choose an integer k (0 <= k <= removable.length) such that, after removing k characters from s using the first k indices in removable, p 
      is still a subsequence of s. More formally, you will mark the character at s[removable[i]] for each 0 <= i < k, then remove all marked characters and check if p is still a
      subsequence.Return the maximum k you can choose such that p is still a subsequence of s after the removals.A subsequence of a string is a new string generated from the original 
      string with some characters (can be none) deleted without changing the relative order of the remaining characters.
      
    Approach:
        1. The brute force approach is simply just going through removable, and checking if by removing the current index from s continues to have p be a subsequent of s. 
        However, there is a trick that we can use to speed up this approach, and that is by using binary search
        2. We will simply run a binary search on the removable vector, where the lower bound is 0, and the upper bound
            is the rightmost index of removable. In each iteration of the binary search, we will check if removing k-characters usingh the removable vector will continue to have
            p be a subsequent of s. If it does, we will increase k and update our maximum k, if not then we will decrease k
        3. In order to make our code cleaner, we will check if the two strings are subsequent in a helper function. If p is still subsequent to s after k-removals than we will return 
            true, if not we will return false
        4. Continue steps 2-3 until our lower bound crosses our upper bound, just like a binary search
*/

//helper function to check if p is subsequent of s after k-removables
    bool isSubsequent(string s, string p, vector<int>removable, int k) {

        int index = 0, letters_found = 0;

        for(int i = 0; i < k; i++) {
            //simulates removing the first k-indexes in removable by making the values of the indexes a number, can be any char other than a lowercase english letter
            s[removable[i]] = '5';
        }

        //record the letters found in s that are also in p after k-removals
        while (index < s.length() && letters_found < p.length()) {

            if (s[index] == p[letters_found]) {
                letters_found++;
            }

            index++;
        }

        //if all letters in p have been found then that means that p is subsequent of s
        return letters_found == p.length(); 
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {

        // Perform a binary search for MAXIMUM k-value
        int min = 0, max = removable.size(), res = 0;

        while (min <= max) {
            int k = (min + max) / 2;
            //test k-value by calling helper function
            bool valid_k = isSubsequent(s, p, removable, k);

            if (valid_k) {
                // p is still a subsequence of s when k elements are removed, try a greater k
                if(k > res) {
                    //update max variable
                    res = k;
                }
                min = k + 1;
            } else {
                // p is not a subsequence of s with the current k-value, try a lower k
                max = k - 1;
            }
        }

        return res;
    }
};
