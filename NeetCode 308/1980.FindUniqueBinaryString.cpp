class Solution {
public:
    /*
        Problem:
          You are given a string s that consists of only digits.
          Check if we can split s into two or more non-empty substrings such that the numerical values of the substrings are in descending order and the difference 
          between numerical values of every two adjacent substrings is equal to 1.
          For example, the string s = "0090089" can be split into ["0090", "089"] with numerical values [90,89]. The values are in descending order and adjacent values differ by 1, so this way is valid.
          Another example, the string s = "001" can be split into ["0", "01"], ["00", "1"], or ["0", "0", "1"]. However all the ways are invalid because they have numerical values [0,1], [0,1], and [0,0,1] respectively, all of which are not in descending order.
          Return true if it is possible to split s​​​​​​ as described above, or false otherwise. A substring is a contiguous sequence of characters in a string.

        Approach:
            1. Create all possible combinations of n lengthed binary strings and store them in a list
            2. Store the binary strings in nums into a set, after creating all n lengthed
                combinations of binary strings, iterate through them, and if the set does not contain
                a binary string, return this binary string
    */

    // helper function to create all binary strings of length n
    void createBinaryStrings(vector<string>& binary_strings, string& curr, int n) {

        if(curr.length() >= n) {
            binary_strings.push_back(curr);
            return;
        }

        curr += "0";
        createBinaryStrings(binary_strings, curr, n);
        curr.pop_back();

        curr += "1";
        createBinaryStrings(binary_strings, curr , n);
        curr.pop_back();

    }
    string findDifferentBinaryString(vector<string>& nums) {

        // store the binary strings in nums into a set
        unordered_set<string> st;
        for(string s : nums) st.insert(s);

        // create all binary strings of the length of the elements in nums
        int binary_string_length = nums[0].length();
        vector<string> all_binary_strings;
        string current_binary_string;
        createBinaryStrings(all_binary_strings, current_binary_string, binary_string_length);

        // check if the set does not have a binary string that we created
        for(string s : all_binary_strings) {
            
            if(!st.count(s)) {
                return s;
            }
        }

        return "";
        
    }
};
