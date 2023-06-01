class Solution {
public:

/*

    Problem:
        You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
        Evaluate the expression. Return an integer that represents the value of the expression.
        Note that:The valid operators are '+', '-', '*', and '/'.Each operand may be an integer or another expression.The division between two integers always truncates toward zero.
        There will not be any division by zero.The input represents a valid arithmetic expression in a reverse polish notation.
        The answer and all the intermediate calculations can be represented in a 32-bit integer.
---------------------------------------------------------------------------------------------
    Approach:
        1. For this problem we will be utilizing a stack in order to maintain the correct
            order of operations 
        2. We will iterate through all the tokens, if a current token is a number, then we 
            can add it to the stack and wait for later to do something with it
        3. If the current token is not a number, this means that we must do some type of 
            operation, so we need the two most recent elements from the stack. Based on the 
            type of operation perform the operation in this order:
            second top most element {operation} top most element -> push this result onto the 
            stack
        4. By doing it this way, other than the first and last iteration, we will always
            have at least 2 numbers in the stack, and when we push into the stack we are
            basically just condensing two numbers into 1 based on the operation we are given.
            Also, we will be left with 1 number in the stack at the end, so we can just
            return the top of the stack.
        5. The reason why we do not have to worry about the order of operations, specifically
            the parenthesis, is beacuse the stack takes care of this for us. By using a stack,
            we are not performing operations from left to right, but rather in a way that is 
            responsive to when operations appear. And this so happens to perfectly align to
            if we were using parenthesis 
*/
    int evalRPN(vector<string>& tokens) {
        
        //declare stack
        stack<int> st;
        
        //perform Reverse Polish Notation Algorithm
        for(int i = 0; i < tokens.size(); i++) {
        
            //get the current token
            string token = tokens[i];

            //case 1: size of stack is size 1 or current token is a number, add this number to the stack
            if(token.size() > 1 || isdigit(token[0])) {
                st.push(stoi(token));
                continue;
            }

            //obtain the two topmost elements in the stack
            int topElement = st.top(); 
            st.pop();
            int secondTopElement = st.top();
            st.pop();


            //case 2: current token is not a number. peform the necessary operations and add the result to the stack
            if(token == "+") {
                st.push(secondTopElement + topElement);
            }else if(token == "-"){
                st.push(secondTopElement - topElement);
            }else if(token == "*") {
                st.push(secondTopElement * topElement);
            } else {
                st.push(secondTopElement / topElement);
            }
        }

        //return the top of the stack
        return st.top();
    }
    
};
