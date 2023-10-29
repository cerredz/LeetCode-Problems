class Solution {
public:
    /*
        Problem:
          You are given an array of non-negative integers nums and an integer k. In one operation, you may choose any element from nums and increment it by 1.
          Return the maximum product of nums after at most k operations. Since the answer may be very large, return it modulo 109 + 7. Note that you should maximize the product 
          before taking the modulo. 

        Approach:
            1. Note that if we have a two numbers, 10 and 2, incrementing the smaller number will ALWAYS result in a 
                bigger product, (thought of this idea after thinking about having a 0 in the list)
            2. Step 1 would not be true if there were negative numbers, but we are being given an array of NON-negative
                numbers
            3. We can sort nums by using a min heap, and using the min heap we can increment the smallest number
                in the heap k times
            4. After incrementing the smallest number k times, traverse through the heap and add the product of all 
                numbers
    */
    int maximumProduct(vector<int>& nums, int k) {
        
        
        // sort numbers using min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums) pq.push(i);

        // increment smallest number in heap k times
        while(k > 0) {
            int smallest = pq.top() + 1;
            pq.pop();
            pq.push(smallest);
            k--;
        }

        // traverse thorugh min heap and calculate running product
        long long runningSum = 1; 
        int MOD = 1e9 + 7;
        while(!pq.empty()) {
            runningSum = (runningSum * pq.top()) % MOD;
            pq.pop();
        }

        return runningSum % MOD;
        

    }
};
