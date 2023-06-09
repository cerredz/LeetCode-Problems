class StockSpanner {
public:

/*
    Problem:
        Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
        The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or
        equal to the price of that day.
        For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, 
        the price of the stock was less than or equal 2 for 4 consecutive days.
        Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, 
        the price of the stock was less than or equal 8 for 3 consecutive days.
        
        Implement the StockSpanner class:
        StockSpanner() Initializes the object of the class
        int next(int price) Returns the span of the stock's price given that today's price is price.

---------------------------------------------------------------------------------------------
    Approach:
        1. When create the StockSpanner object we must use a stack, but not just any stack,
            we must use a monotonic stack in order to save time in the next algorithmn
        2. For each stack entry, we will keep track of the price of the stock, and 
            how many days this stock "spanned"
        3. For example, if u have the sequence 3,2,1,5. Instead of having to loop through the
            stack 4 times in future iterations, we will push onto the stack (5,4), indicating
            that the number 5 has spanned for 4 days. This way in future iterations we will 
            not have to iterate 4 times for the 4 numbers, but rather only 1 time over the 5
        4. In the next algorithmn, have a counter variable and while the stack is not empty
            and the first paramter of the top of the stack is < the price parameter
            we can add the second parameter of the top of the stack to the the counter. then
            pop from the stack.
        5. After step 5, push the price and counter variables onto the stack, and return the
            counter variable
----------------------------------------------------------------------------------------------
*/
    //first parameter is price, second parameter is span
    stack<pair<int,int>> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        //declare counter variables
        int numLower = 1;

        //while we continue to find a smaller number, condense it to make a smaller stack
        while(!prices.empty() && prices.top().first <= price) {
            numLower += prices.top().second;
            prices.pop();
        }

        //create a new stack entry with the condensed information
        prices.push({price, numLower});
        return numLower;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
