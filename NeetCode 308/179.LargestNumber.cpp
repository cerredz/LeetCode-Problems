class Solution {
public:
/*

    Problem:
      Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
      Since the result may be very large, so you need to return a string instead of an integer.
----------------------------------------------------------------------------------------------
    Approach:
        1. Store the nums in list of strings opposed to a list of integers
        2. We can sort this list of strings in a way that, when we iterate back through it, 
            will automatically give us the highest possible number
        3. When Getting the highest possible number betwewn two strings (a and b), the highest
            number is either a + b or b + a, apply this method to when we sort our list of 
            strings
        4. When our list of strings is sorted, iterate back through it and concatinate
            the strings to our result
------------------------------------------------------------------------------------------------
    Psuedocode:
        - create a res variable, and a list of strings

        - for every number in nums:
            - add current number to list of strings

        - sort nums in a way that will give us the highest possible number

        - for every string in our list of strings:
            - add current string to res
        
        - return res
------------------------------------------------------------------------------------------------
*/
    string largestNumber(vector<int>& nums) {
        

        vector<string> numStrings;
        string res = "";

        //convert list of ints to list of strings
        for(int num: nums) {
           numStrings.emplace_back(to_string(num));
        }

        //sorted list of strings in a way that will give us highest possible number
        sort(numStrings.begin(), numStrings.end(), [](const string& a, const string& b) {
            //takes two numbers and returns the highest possible number 
            return a + b > b + a;
        });

        //concatinate strings to one giant string
        for(string str : numStrings) {
            res += str;
        }

        if(res[0] == '0') {
            //if we get a number like "00000", they want us to output it at just "O"
            return "0";
        }

        return res;

    }
};
