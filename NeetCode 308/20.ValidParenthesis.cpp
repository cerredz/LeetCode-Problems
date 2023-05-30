class Solution {
public:

/*
    Problem:
    
        Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
        An input string is valid if: Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order.
        Every close bracket has a corresponding open bracket of the same type.
-----------------------------------------------------------------------------------------------------------------
    Approach:
        1. We must utilize a stack for this problem in order to look at previos brackets when encountering a
            closed bracket
        2. We will iteraate through each letter in s, and if the current character is an open bracket then 
            we will insert it into the stack.
        3. When we encounter a closed bracket we must check several things:
            - is the stack empty
            - does the closed bracket match the most recent opened bracket
        4. If either of these things are false, then we can return false. This is because if the stack is already
            empty when we reach a closed bracket this means that there is 1 more closed bracket than opened 
            bracket, hence there is no corresponding opened bracket for the closed bracket. Also, we can check
            the most recent opened bracket by looking at the top of the stack
        5. If both cases are true, then we can pop from the stack and move to the next iteration
        6. After iterating through s, return true IF AND ONLY IF the stack is empty. If it is not empty this
            means that we have extra opened brackets that do not have a corresponding closing bracket
---------------------------------------------------------------------------------------------------------------
*/
    bool isValid(string s) {
        //declare stack
        stack<char> st;

        //iterate through s and implement the algorithm
        for (char bracket : s) {

            //insert opened brackets into the stack
            if (bracket == '(' || bracket == '[' || bracket == '{') {
                st.push(bracket);

            //we have found a closed bracket
            } else {

                //case 1: check if stack is empty
                if (st.empty()) {
                    return false;
                }

                //case 2: check for matching most recent opened bracket
                if ((bracket == ')' && st.top() != '(') ||
                    (bracket == ']' && st.top() != '[') ||
                    (bracket == '}' && st.top() != '{')) {
                    return false;
                }

                st.pop();
            }
        }

        //return true IF AND ONLY IF the stack is empty
        return st.empty();
    }
};
