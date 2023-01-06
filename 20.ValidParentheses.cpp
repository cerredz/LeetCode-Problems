class Solution {
public:
    bool isValid(string s) {
        

        /*
            Approach / Pseudocode:

            - initialize a stack
            - loop through all the letters of S
                - if the current letter is an open parenthese
                    - push the letter on the stack
                - else
                    - if the stack is not empty
                        - if the current letter is a closed parenthese and the top of the stack is not the matching open parenthese
                            - return false because this violates rule #2
                    - st.pop()

            - if the stack is empty we can return true, otherwise we return false
        */
        stack<char> st;

        for(auto i : s){

            if(i == '(' || i == '{' || i == '['){ // push all open parentheses into the stack
                st.push(i);
            }
            else
            {
                //st.top() will return the most recent open parenthese
                // if i (current Letter) is not the matching closed parenthese, we can return false because we found a non-matching bracket
                if(st.empty() || (st.top() == '(' && i != ')')) return false;
                if(st.empty() || (st.top() == '{' && i != '}')) return false;
                if(st.empty() || (st.top() == '[' && i != ']')) return false;

                st.pop();//if we reach this far it means we got a matching pair of brackets, so we can pop from the stack
            }
        }

        return st.empty();//if the stack is not empty then we have an extra open parenthese, which is why we retuen st.empty()
    }
};
