class Solution {
public:
/*
    Problem:
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses
---------------------------------------------------------------------------------------------
    Approach:
        1. We can break this problem down into smaller subproblems, simple by starting at just
            1 opened parenthese. For example(if n > 2), from ( you can get to () or ((, from
            ( you can get to ((( or (() and so on
        2. For this reason we can use recursion for this problem, we will need to keep track
            of the amount of opened and closed brackets in the string that we are 
            passing into the recursive function
        3. Cases that we muust follow in the recursive algorithmn: 
            - we will be starting at the smallest possible string
            - in order for the parenthesis to be valid the number of closed brackets
                must be less than or equal to the number of closed brackets (all strings
                generated from the recursive function must be a valid parenthese)
            - the number of opened brackets must not exceed n
            - if the number of opened and closed brackets both equal n then the string
                belongs in the output
----------------------------------------------------------------------------------------------
    Psuedocode:

        - recurFunction(n, open, close, str, res ) {

            - if open and close both equal n
                - add str to res and return
            
            - if open < n
                - recurFunction(n, open + 1, close, str + "(", res)
            
            - if close < open
                - recurFunction(n, open, close + 1, str + ")", res)
        }


        - declare vector of strings(res), 
        - call recurFunction with correct parameters
        - return res

        
---------------------------------------------------------------------------------------------
*/
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        generateRecursive(n, 0, 0, "", result);
        return result;
    }

private:
    void generateRecursive(int n, int open, int close, string current, vector<string>& parenthesis) {
                //case 1: equal amount of open and closed brackets, add to result
                if(open == n && close == n) {
                    parenthesis.push_back(current);
                    return;
                } 

                //case 2: number of open brackets is less than n, create a new string with another opened bracket
                if(open < n) {
                    generateRecursive(n, open + 1, close, current + "(", parenthesis);
                }

                //case 3: num of close brackets < num of opened brackets, this make sure that we have a valid parenthese, add a closed bracket to the end
                if(close < open) {
                    generateRecursive(n, open, close + 1, current + ")", parenthesis);
                }

            }
    
};
