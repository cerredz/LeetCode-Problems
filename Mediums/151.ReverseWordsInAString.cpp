class Solution {
public:
    /*
        Problem:
          Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters. 
          The words in s will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space.
          Note that s may contain leading or trailing spaces or multiple spaces between two words. 
          The returned string should only have a single space separating the words. Do not include any extra spaces.

    
    */
    // helper function to reverse a singular word
    void reverseString(string& str) {
        int n = str.length();
        for(int i = 0; i < n / 2; i++) {
            char temp = str[i];
            str[i] = str[n - 1 - i];
            str[n - 1 - i] = temp;
        }
    }
    string reverseWords(string s) {
        stack<char> st;

        // skip all of the leading spaces
        int n = s.length();
        int index = 0;
        while(index < n && s[index] == ' ') {
            index++;
        }

        // add letters to a stack, and eliminate the gaps of more than one space
        for(int i = index; i < s.length(); i++) {
            if(!st.empty() && st.top() == ' ' && s[i] == ' '){
                cout << "skipped" << endl;
                continue;
            }
            st.push(s[i]);
        }

        // edge case, remove trailing space
        if(st.top() == ' ') st.pop();

        // stack reversed the string, now just pop from the stack and reverse the words
        string res = "", curr = "";
        while(!st.empty()) {
            char letter = st.top();
            cout << letter;

            if(letter == ' ') {
                reverseString(curr);
                res += curr + ' ';
                curr = "";
            } else {
                curr += letter;
            }
            st.pop();
        }

        // reverse the last word
        reverseString(curr);
        res += curr;

        return res;
    }
};
