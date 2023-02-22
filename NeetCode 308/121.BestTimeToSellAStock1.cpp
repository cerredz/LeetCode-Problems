class Solution {
public:

/*
    Problem:
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
-------------------------------------------------------------------------------------------------------------------------
    Approach: 
        1. Loop through the vector of prices, keep track of the lowest number seen
        2. Have a variable to keep track of the biggest progfit, if the current number minus the lowest number seen is 
            greater than the current max profit, then update the max profit
        3. return the max profit after looping through the vector of prices
-------------------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare maxProfit and cheapestPrice variables
        - for every number in profit:
            - if the current number if less than cheapestPrice
                - set cheapestPrice equal to the number
            
            - if the current number - cheapestPrice is greater than the current maxProfit:
                - set maxProfit to the currentNumber - cheapestPrice
        
        - return maxProfit

*/

    int maxProfit(vector<int>& prices) {
         
        int maxProfit = 0, cheapestPrice = 10000000;

        for(int i = 0; i < prices.size(); i++) {

            cheapestPrice = min(cheapestPrice, prices[i]);//lowest price seen so far
            maxProfit = max(maxProfit, prices[i] - cheapestPrice);// greatest profit possible using lowest price

        }
        
        return maxProfit;


    }
};
