class Solution {
public:

/*
    Problem:
      You are given a 0-indexed m * n integer matrix values, representing the values of m * n different items in m different shops. 
      Each shop has n items where the jth item in the ith shop has a value of values[i][j]. 
      Additionally, the items in the ith shop are sorted in non-increasing order of value. 
      That is, values[i][j] >= values[i][j + 1] for all 0 <= j < n - 1. On each day, you would like to buy a single item from one of the shops. 
      Specifically, On the dth day you can: Pick any shop i. Buy the rightmost available item j for the price of values[i][j] * d. 
      That is, find the greatest index j such that item j was never bought before, and buy it for the price of values[i][j] * d. Note that all 
      items are pairwise different. For example, if you have bought item 0 from shop 1, you can still buy item 0 from any other shop.
      Return the maximum amount of money that can be spent on buying all m * n products.
*/
    long long maxSpending(vector<vector<int>>& values) {
        int n = values.size(), m = values[0].size();
        long long res = 0;  
        vector<int> items_bought(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for(int i = 0; i < n; i++) {
            min_heap.push({values[i][m - 1], i});
        }

        long long day = 1;  // Use long long for day counter
        while(!min_heap.empty()) {
            auto [price, store] = min_heap.top();
            min_heap.pop();
            res += static_cast<long long>(price) * day;  // Use static_cast and multiply by day
            items_bought[store]++;
            day++;  // Increment day
            if (items_bought[store] < m) {
                min_heap.push({values[store][m - items_bought[store] - 1], store});
            }
        }
        return res;
    }
};
