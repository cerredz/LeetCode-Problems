class Solution {
public:


/*
    Problem:
      A conveyor belt has packages that must be shipped from one port to another within days days.
      The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
      We may not load more weight than the maximum weight capacity of the ship.
      Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/
    //Step 3: create a helper function that checks if a certain capacity can ship all of the weights in n days
    bool populate(vector<int>& weights, int n, int capacity) {

        int runningSum = 0, containers = 1;

        for(int i = 0; i < weights.size(); i++) {

           runningSum += weights[i];

           if(runningSum > capacity) {
               containers++;
               runningSum = weights[i];
           }
        }

        return containers <= n;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        //Step 1: obtain the max value from weights, and calculate the sum of all the number in weights
        int max = -10000, sum = 0;
        for(int i : weights) {

            if(i > max) {
                max = i;
            }
            sum += i;
        }

        //Step 2: Set up a binary search using the max as our lower bound and the sum as our upper bound, we want to use binary search on the ship's capacity size with these bounds
        int res = sum;
        while(max <= sum) {
            int mid = (max + sum) / 2;


            //Step 4: If the current capcity(mid) can ship the elements in weights within days, then update res if it is the lowest capacity that we have seen
            if(populate(weights, days, mid)) {
                res = min(res, mid);
                sum = mid - 1;
            } else {
                max = mid + 1;
            }

        }

        return res;
        
    }
};
