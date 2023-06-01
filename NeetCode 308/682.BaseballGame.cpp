class Solution {
public:

/*

    Problem:
    You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
    You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following: An integer x.
    Record a new score of x.'+'.Record a new score that is the sum of the previous two scores.'D'.Record a new score that is the double of the previous score.'C'.
    Invalidate the previous score, removing it from the record.
    Return the sum of all the scores on the record after applying all the operations.
    The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.
----------------------------------------------------------------------------------------------
    Approach:
        1. We need a stack in order to be able to correctly backtrack for this problem
        2. We will iterate through operations, and handle the 4 different cases that can be in operations
        3.  If the current operation is a +, then add the previous 2 elements in the STACK, not the vector,
            and push the sum into the stack
        4. If the current operation is a  "D", look at the top of the stack and push (top * 2) into the 
            stack
        5. If the current operation is a "C", then pop from the stack
        6. You can either calculate the runs inside of each case, or wait until we iteration through operations
            and go through the stack until it is empty at the end
----------------------------------------------------------------------------------------------
*/
    int calPoints(vector<string>& operations) {

        //declare variables
        int runs = 0;
        stack<int> st;

        //perform the algorithm involving a stack,  we will be updating the runs as we go
        for (const string& op : operations) {
            //case 1: double previous score
            if (op == "D") {
                st.push(st.top() * 2);
                runs += st.top();
            
            //case 2: invalidate previous score
            } else if (op == "C") {
                runs -= st.top();
                st.pop();

            //case 3: add sum of previous two scores
            } else if (op == "+") {
                int prev = st.top();
                st.pop();
                int prev_prev = st.top();
                st.push(prev);
                st.push(prev+ prev_prev);
                runs += st.top();
            
            //case 4: record a new score
            } else {
                st.push(stoi(op));
                runs += st.top();
            }
        }

        return runs;
    }
};
