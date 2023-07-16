class Solution {
public:

/*

    Problem:
      Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
      Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, 
      she eats all of them instead and will not eat any more bananas during this hour. Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
      Return the minimum integer k such that she can eat all the bananas within h hours.


    Approach:
        1. For this problem there we are trying to minimize k, however the brute force approach, where we try every 
            possible k value in between the min and max value of piles will be too much
        2. However, we know that there is a lower and upper bound for k, minimum and maximum value in piles, 
            so we can solve this problem using binary search
        3. Every iteration in the binary search, we will calculate the middle value between the curent min and max,
            and looping through piles using this value to see if it can eat all of the bananna in h hours. If it takes 
            too long, this means that we need a bigger k value, and set the min value to the mid value + 1. If it is
            within h hours we want to test a smaller k value, so we will set the max value to the mid value. The reason
            why we are not returning anything in the binary search is beacuse we are trying to find the MIMIMUM k-value
            in other words, multiple k values can take the same h hours to eat the bannanas
        4. We will also have a seperate kMin variable that keeps track of the minimum k value that works
        
*/

    //helper function to calculate the amount of days a k value will take to eat all of the bannanas
    bool eatingSpeed(vector<int>& piles, int h, int k ) {

        long long days = 0;

        //simulate Koko eating the bananas
        for(int i = 0; i < piles.size(); i++) {

            if(piles[i] < k) {
                days++;
            } else if (piles[i] % k == 0) {
                days += (piles[i] / k);
            } else {
                days += ((piles[i] / k) + 1);
            }
        }

        //if days is less than or equal to hours, return true
        return days <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        

        //declare variables
        int min = 1;
        long long max = -1000000;


        //find the upper and lower bounds for the binary search
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] > max) {
                max = piles[i];
            } 
        }

        //set res to biggest value in c++
        long long res = 9223372036854775807;

        //perform the binary search
        while(min <= max) {

            int mid = (min + max) / 2;
            //simulate Koko eating bananas
            bool valid_k = eatingSpeed(piles,h,mid);

            //if koko ate bananas within h hours, we want to try a smaller number in order to mimmize k
            if(valid_k) {
                if(mid < res){
                    res = mid;
                }
                max = mid - 1;
            //if koko didnt eat the bananas in h hours, we want to try a bigger number in order to stay within h hours
            } else {
                min = mid + 1;
            }
        }

        return res;

    }
};
