class Solution {
public:

/*
    Problem:
        Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
        Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
-----------------------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach, we will use a one int variable (curr) to keep track of 
            the number of vowels in a given window, and another int variables (vowels) to keep track of the 
            most vowels seen in a k-lengthed window of the whole string
        2. Start our by counting how many vowels there are in the first k elements, k is at least the size of
            s, so no out of bounds errors will occur here. Store this values in vowels
        3. Start iteration from k -> s.length, at each iteration, if the current character is a vowel then 
            increment the curr variables, and if the first letter of the window (i - k) is a vowel then 
            decrement the curr variable
        4. At the end of each iteration, check if the curr variables if greater than the res variable,
            and update accordingly
----------------------------------------------------------------------------------------------------------------
*/
    int maxVowels(string s, int k) {

        //declare variables
        int vowels = 0, currVowels = 0;
        
        //count vowels in first k-elements
        for(int i = 0; i < k; i++) {

            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                currVowels++;
            }
            
        }

        vowels = currVowels;

        //implement sliding window algorithmn, keep moving the window to the right by 1
        for(int i = k; i < s.length(); i++) {

            //update curr based on if vowels found or not
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                currVowels++;
            }
            if(s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
                currVowels--;
            }
            
            //compare current window of vowels to max vowels so far
            vowels = max(vowels, currVowels);
            
        }
        

        //return max vowels
        return vowels;
    }
};
