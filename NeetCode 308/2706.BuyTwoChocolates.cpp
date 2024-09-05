class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min_price = 101, smin_price = 101;
        int res = 0;

        // get the two smallest prices in the list
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min_price) {
                smin_price = min_price;
                min_price = prices[i];
            } else if(prices[i] < smin_price) {
                smin_price = prices[i];
            }
        }

        // see if two smallest prices are less than the money that we have
        if(min_price + smin_price <= money) return money - min_price - smin_price;
        return money;
    }
};
