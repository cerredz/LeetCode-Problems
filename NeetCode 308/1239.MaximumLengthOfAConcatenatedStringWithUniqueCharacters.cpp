class Solution {
public:
    /*
        Problem:
          You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
          Return the maximum possible length of s. A subsequence is an array that can be derived from another array by deleting some or no elements without 
          changing the order of the remaining elements.


        Approach:
            1. We will get all combinations of arr using backtracking
            2. For each combination, if the combination has no duplicate letters
                then compare it to the maxLength we found so far
    */

    void getMaxLength(vector<string>& arr, string curr, int& max_length, int index) {

        if (index >= arr.size()) {
            max_length = max(max_length, int(curr.length()));
            return;
        }

        // Try including the current string from arr
        string include_curr = curr + arr[index];
        unordered_set<char> st(include_curr.begin(), include_curr.end());
        if (include_curr.length() == st.size()) {
            max_length = max(max_length, int(include_curr.length()));
            getMaxLength(arr, include_curr, max_length, index + 1);
        }

        // Try excluding the current string from arr
        getMaxLength(arr, curr, max_length, index + 1);
    }


    int maxLength(vector<string>& arr) {
        

        string current_combination = "";
        int res = 0;
        getMaxLength(arr, current_combination,res, 0);
        return res;
    }
};
