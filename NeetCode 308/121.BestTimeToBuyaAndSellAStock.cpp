class Solution {
public:

/*

    Problem:
        You are given an array prices where prices[i] is the price of a given stock on the ith day.
        You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
        Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
-----------------------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window appoach, where the left of our window is the current lowest stock
            price, and the right of the window is our current index
        2. We will be keeping stack of the lowest current index and the different between  
            the current index and our lowest stock price at every iteration
        3. For every iteration we will update our min stock variable if it is the lowest stock price we have
            seen so far, because we can only sell stocks in the future, the numbers to the left of this number
            do not matter. Therefore, if we see a new low number we are sliding our window to the right
        4. Since we are keeping track of the greatest difference, at every iteration check if the current index
            minus the min stock is bigger than the greatest difference so far, if it is then update it
        5. Return the greatest difference we find between two stocks
----------------------------------------------------------------------------------------------------------------
    Psuedocode:

        - declare variable to keep track of min stock, and variable to keep track of greatest difference

        - for every price in prices:

            - if we find a value lower than our min stock, then set min stock to that value

            - if the current price - min stock is > greatest difference, then update the greatest difference

        - return the greatest difference
*/

    int maxProfit(vector<int>& prices) {
         
        int res = 0, minStock = 100000000;

        for(int i = 0; i < prices.size(); i++) {

            if(prices[i] < minStock){
                minStock = prices[i];
            }

            res = max(res, prices[i] - minStock);
        }

        return res;


    }
};
