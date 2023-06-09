class Solution {
public:

/*
    Problem:
      Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith 
      day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
----------------------------------------------------------------------------------------------
    Approach:
        1. We must using a stack in order to dynamically backtrack for this problem
        2. We will push both the temperature and the index this temperature occured as a pair
            onto the stack
        3. Before, doing step 2, we must check the conditions for when we reach a warmer
            temperature. While the stack is not empty and the top of the stack is less
            than the current temperature this means that we have found a warmer temperature
        4. Since we are also keeping track of temperatures in the stack, we can add
            the current index - colder temperature (top of the stack) to a vector at the 
            position of the colder temperature(top of the stack)
        5. Repeat steps steps 2-4 for every temperature in temperatures, and then return the 
            result vector
----------------------------------------------------------------------------------------------

*/
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        //declare variables
        vector<int> res (temperatures.size(), 0);
        stack<pair<int,int>> st;

        //implement algorithmn using stack
        for(int i = 0; i < temperatures.size(); i++) {

            //while we have found a warmer temperature
            while(!st.empty() && st.top().first < temperatures[i]) {

                //update corresponding index in res vector
                res[st.top().second] = i - st.top().second;
                st.pop();
            }

            //push the current temperature and index of current temperature onto the stack
            st.push({temperatures[i], i});
        }

        return res;
    }
};
