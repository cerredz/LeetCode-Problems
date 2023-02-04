class Solution {
public:

/*
    Problem:
      Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
      You can use each character in text at most once. Return the maximum number of instances that can be formed.
    ------------------------------------------------------------------------------------------------------------
    Approach:
        - loop through the string and keep track of the frequencies of characters
        - then, decrement the characters of 'balloom' in the vector until one of them is less than 0,
            while decrementing the characters make sure to keep a counter of how many times you fully 
            decremented every character
    ------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare result variabale, and boolean variable to have as a condition for the while loop(lettersRemaining)
        - declare vector to keep track of characters(charFreq)
        - for each character(c) in text:
            - increment charFreq[c]

        - while lettersRemaining is true:
            - if you have enough characters to form 'balloon'
                - increment result
                - decrement all characters in 'balloon' in the vector
            - else
                - set lettersRemaining to false
        
        - return result
*/
    int maxNumberOfBalloons(string text) {
        int res = 0, lettersRemaining = true;
        vector<int> charFreq(26,0);//map of character frequencies

        for(char c : text) {
            charFreq[c - 'a']++;
        }

        while(lettersRemaining) {
            
            //time to check for is 'balloon' can be formed
            if(charFreq['a' - 'a'] > 0){
                if(charFreq['b' - 'a'] > 0){
                    if(charFreq['l' - 'a'] > 1){
                        if(charFreq['o' - 'a'] > 1){
                            if(charFreq['n' - 'a'] > 0){//indiviually checks for every character in 'balloon
                                res++;
                                charFreq['a' - 'a']--;
                                charFreq['b' - 'a']--;
                                charFreq['l' - 'a'] -=2;
                                charFreq['n' - 'a']--;
                                charFreq['o' - 'a']-= 2;

                            }else {//must have else statement every step because even if 1 letter isnt frequent 
                                    //enough to form 'balloon', then we cannot increment res
                                lettersRemaining = false;
                            }
                        }else {
                            lettersRemaining = false;
                        }
                    }else {
                        lettersRemaining = false;
                    }
                }else {
                    lettersRemaining = false;
                }
            }else {
                lettersRemaining = false;
            }
        }
    

        return res;
    }
};
