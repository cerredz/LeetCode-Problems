class Solution {
public:

/*

    Problem:

      Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
      
    Apporoach:
        1. For this problem we must backtrack to previous digits in some cases, but we will not actually need a stack
            in order to reduce memory usage. We can just use and string and utilize the string functions to mimic 
            everything a stack would do in this problem
        2. We will iterate through num and compare the value of the current index with the value of previous indexes.
            If the previous value(value at the top of the "stack") is greater than the current value, then pop from 
            the stack and decrement k. 
        3. Remember, we can only remove k elements, so continue step 2 until either k is less than 1, the stack is 
            empty, or we run in to value that is less than the current index
        4. Notice that by following steps 2 and 3 the number "0" might occur at the first element of the string, 
            however we dont want to lead our answer with a 0, so if the only element in the string is 0 then we can 
            remove it, check this at every index
        5. There is one type of test case we are missing from steps 2-4, and that is if num is a sequence of all 
            increasing singular digits. For example, 112, 23489, 123456789, etc. In this case we do not pop anything 
            from the back, and we will still kave k pops left since k is always greater than 0. In this case,
            we pop from the back of the string k times if the stack if still not empty
*/
    string removeKdigits(string num, int k) {


        //declare string
        string res = "";

        //edge case: answer will always be '0' if k > or = length of nums
        if (k >= num.length()) {
            return "0";
        }

        //implement approach
        for (char c : num) {
            
            //pop back element if all cases from step 2 are true
            while (k > 0 && !res.empty() && c < res.back()) {
                res.pop_back();
                k--;
            }

            //make sure we dont lead our answer with a 0
            if (res.empty() && c == '0') {
                continue;
            }

            //add digit onto back of string
            res.push_back(c);
        }

        //if there are still k pops left where k > 0, remove the last k elements 
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }

        //still need to check if stack is empty beacuse text cases can have alot of 0's in it, resulting from the above while loop removing all digits from the string
        if (res.length() == 0) {
            return "0";
        }

        return res;
    }
};
