class Solution {
public:

/*
    Problem:
        Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on 
        an initially empty stack, or false otherwise.
----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a stack for this problem in order to simulate the explanation
            given to us
        2. We also need two pointer for this problem, one pointer for the current index
            of pushed and one pointer for the current index of popped
        3. The goal is to run into the number at popped[j] in pushed, and while iterating 
            up until that number to add all of the numbers encountered into the stack. For
            example, in example 1 since the first number in popped is 4, we will add numbers
            1,2,3,4 into the stack since the they all come before 4
        4. When we finally run into the 4, we will increment the right pointer and continue
            to pop from the stack until the top of the stack is not equal to popped[right
            pointer]
        5. Notice how we are popping the elements in the order that they are supposed to be
            popped. Once we run into a number in popped, if it is at the top of the stack
            we pop it. This means that if we run into a number in popped, and the
            corresponding number is not at the top of the stack, then the number will never
            be popped.
        6. This means that after we are done iterating through popped and pushed, we only
            want to return true if the stack is empty, because if this is the case then 
            this means that all of the number were popped in the correct order
----------------------------------------------------------------------------------------------
*/
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        

        //declare vartiables
        stack<int> st;
        int right = 0;

        //implement stack algorithm
        for(int left = 0; left < pushed.size(); left++) {

            //push left pointer onto the stack
            st.push(pushed[left]);

            //while the top of stack is = right pointer
            while(!st.empty() && st.top() == popped[right]) {
                right++;
                st.pop();
            }
        }

        //only return true if the stack is empty
        return st.empty();


    }
};
