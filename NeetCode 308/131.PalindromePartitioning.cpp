class Solution {
public:


    /*
        Problem:
            Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s
            
        Approach:
            1. get all paritions of s using backtracking
            2. using the paritions, compute whether or not all substrings in a partition is a palindrome, 
            3. If all substrings in a partitions is a palindrome, then add this to the result
    */

    // helper function to check whether or not a string is a palindrome from start to end
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    // helper function to create all the unqiue partitions, and check whether or not a partition is a palindrome
    void getPalindromePartitions(vector<vector<string>>& res, string s, int index, vector<string>& part) {

        if(index >= s.length()) {
            res.push_back(part);
            return;
        }

        
        for(int i = index; i < s.length(); i++) {

            if(isPalindrome(s, index, i)) {
                // only do recursive calls if curr string is a palindrome
                string curr (s.begin() + index, s.begin() + i + 1);
                part.push_back(curr);
                getPalindromePartitions(res, s, i + 1, part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        
        vector<vector<string>> all_partitions;
        vector<string> current_partitions;
        getPalindromePartitions(all_partitions, s, 0, current_partitions);
        return all_partitions;

    }
};
