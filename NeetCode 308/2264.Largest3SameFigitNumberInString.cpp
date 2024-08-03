class Solution {
public:
/*
    Problem:
      You are given a string num representing a large integer. An integer is good if it meets the following conditions:
      It is a substring of num with length 3. It consists of only one unique digit. Return the maximum good integer as a string or an empty string "" if no such integer exists.
Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.

*/
    string largestGoodInteger(string num) {
        string res = "";
        int n = num.length();

        // loop until the third-to-last character
        for(int i = 0; i <= n - 3; i++) {
            if(num[i] == num[i + 1] && num[i] == num[i + 2]) {
                // 3-same-digit found, compare it to res
                string current = num.substr(i, 3);
                if(current > res) {
                    res = current;
                }
            }
        }
        return res;
    }
};
