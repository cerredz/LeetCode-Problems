class Solution {
public:

/*
    Problem: 
      You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
      On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
      However, you can buy it then immediately sell it on the same day. Find and return the maximum profit you can achieve.
-------------------------------------------------------------------------------------------------------------------
    Approach:
        1. At every index We will be keeping track of the highest price and lowest price in a certain index
        2. If the prices[end of window + 1] is less than the highest price, we will add the highest price - the 
            lowest price to the maxprofit.
        3. Once we add to out maxProfit, we must close the window, and set the highest and lowest price to the next 
            number in the vector
        4. Return our maxProfit
--------------------------------------------------------------------------------------------------------------------
    Psuedocode: 
        - declare the following variables: maxProfit, lowestPrice, highestPrice, and end
        //end represents the end of the current window

        - while end is less than the size of the vector
            - if current number is less than lowestPrice, update lowestPrice
            - if current number is greater than highestPrice, update highestPrice

            - if the first number outside of our window is less than the highestPrice
                - add the highestPrice - lowestPrice to maxProfit
                - set both lowestPrice and highestPrice to prices[end + 1]
            
            - increment end
        
        - return maxProfit

*/
  int maxProfit(vector<int>& prices) {
        
        //edge case
        if(prices.size() == 1) {
            return 0;
        }

        int maxProfit = 0, lowestPrice = 1000000, highestPrice = -1, end = 0;

        //while the end of window is still in the vector
        while(end < prices.size() - 1) {

            lowestPrice = min(prices[end], lowestPrice);
            highestPrice = max(prices[end], highestPrice);

            // if next number is < current highest number, we can sell our stock
            if(prices[end + 1] <= highestPrice) {

                //update our profit
                maxProfit += highestPrice - lowestPrice;

                //must slide current window
                lowestPrice = prices[end + 1];
                highestPrice = prices[end + 1];
            }

            end++;
        }

        //must account for last index
        if(prices[prices.size() - 1] > prices[prices.size() - 2]) {
            highestPrice = prices[prices.size() - 1];
            maxProfit += highestPrice - lowestPrice;
        }

        return maxProfit;

        
    }
};
