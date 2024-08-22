class Solution {
public:
/*
    Problem:
      Given a string s, determine if it is valid.
      A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
      Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
      Return true if s is a valid string, otherwise, return false.
*/
    bool isValid(string s) {
        
        if(s.length() % 3 != 0) return false;

        stack<char> st;
        // loop through s, handling each character seperately
        for(int i = 0; i < s.length(); i++) {
            char letter = s[i];
            
            if(letter == 'a') {
                // always push a
                st.push(letter);
            } else if (letter == 'b') {
                // 2 cases for b: either stack is empty or we push onto stack
                if(st.empty()) return false;
                st.pop();
                st.push(letter);
            } else if (letter == 'c') {
                // 2 cases for c: either stack is empty or most recent char is not b
                if(st.empty() || st.top() != 'b') return false;
                st.pop();
            }
        }
        return st.size() == 0;
    }
};
