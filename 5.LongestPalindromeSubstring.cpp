class Solution {
public:
    
    /*
        Approach / Psuedocode
        --------------------------------------------------
        - we will be implementing a sliding window approach:
            - we will start at a single character and increase the window
            in both ways if the window is a valid palindrome
            - if the current sliding window is bigger than the current longest palindrome 
            then we must update the palindrome
        ---------------------------------------------------
        - initialize a string varibale called result
        - for each letter in string s
            --------two cases: odd and even lengthed palidromes-------------
            //handle odd case first
            
                - create two ints(left and right), both equal to i
                - while you exand in each direction and the string is still a palindrome
                    - if the string is larger than result
                        - update result
            //time to handle even case

                set left = i and right = i + 1
                - while you exand in each direction and the string is still a palindrome
                    - if the string is larger than result
                        - update result

        return result
                
    */
    
    string longestPalindrome(string s) {
        
        string result = "";//current longest palindrome

        for(int i = 0; i < s.length(); i++){//must scan through string to check all possible palindromes
            
            //odd case first
            int left = i;
            int right = i;

            while(left >= 0 && right < s.length() && tolower(s.at(left)) == tolower(s.at(right))){
                //if left and right are equal to each other, than the current string (from left -> right),
                //is a valid palindrome
                if(right - left + 1 > result.length()){//if current window is bigger than result we update result
                    result = s.substr(left, (right - left) + 1);
                }
                //now we must increase window
                left--;
                right++;
            }

            //even case

            left = i;
            right = i + 1;
            //from here on is the exact same precedure as the odd case, just had to start the right at i + 1

            while(left >= 0 && right < s.length() && tolower(s.at(left)) == tolower(s.at(right))){
                if(right - left + 1 > result.length()){
                    result = s.substr(left, (right - left) + 1);
                }
                left--;
                right++;
            }

            
        }

        return result;
    }


};
