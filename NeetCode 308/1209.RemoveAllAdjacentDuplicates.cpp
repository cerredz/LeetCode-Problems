class Solution {
public:

/*
    Approach:
        1. We will need to both backtrack and store the frequency of elements in this problem. In this case 
            we can use a stack that takes in a pair as a parameter, where the first parameter is the letter, and the
            second parameter is the frequency of that letter it has appeared
        2. The first thing we must do is simply just iterate through the string and fill in the stack.
            The way we will dill in the stack is as follows:
                - if the current character matches the top character of the string
                    - increment the frequency for that element

                    - if the value for the frequency of this element in the stack has reached k, this means that there
                        are k of the same letter, and these letters must be removed from the ouput, so we pop from 
                        the stack in this case
                - else 
                    - create a new stack entry with the current letter and the value 1, this is the first time seeing
                        the given letter

        3. For each entry in the stack, add the frequency (second parameter) of the letter(first parameter) to the 
            front of the string       

*/
    string removeDuplicates(string s, int k) {
        
        //declare stack that takes in a pair as an input
        stack<pair<int,int>> st;
        string res = "";

        //fill the stack
        for(int i = 0; i < s.length(); i++) {

            //case 1: new character found, create entry
            if(st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});

            //case 2: duplicate character found, increment frequncy and compare to k
            } else {

                st.top().second++;
                if(st.top().second == k) {
                    st.pop();
                }
            }
        }

        //elements in the stack at this point are all k-lengthed duplicates removed from s, add them to res
        while(!st.empty()) {
            res += string(st.top().second, st.top().first);
            st.pop();
        }

        //res is in reverse order since we used stack
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};
