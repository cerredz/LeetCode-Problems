class Solution {
public:


/*
    Problem:
      You are given an array nums of n positive integers.
      You can perform two types of operations on any element of the array any number of times:
      If the element is even, divide it by 2. For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
      If the element is odd, multiply it by 2. For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
      The deviation of the array is the maximum difference between any two elements in the array.
      Return the minimum deviation the array can have after performing some number of operations.
*/
    // helper function to help minimize an even number to its lowest possible value
    int minimizeNumber(int n) {

        while(n > 0 && n % 2 == 0) {
            n /= 2;
        }
        return n;
    }

    int minimumDeviation(vector<int>& nums) {
        
        // our first step is to store the lowest possible value of each number in nums into a min heap.
        // we also want to be able to know the original nuumber the minimized number came from, so 
        // also store the original number into the heap in the form of a pair
        // when minimizing each number, we also want to keep track of the greatest number in order
        // to calculate the deviation of nums
        int n = nums.size(), maxNum = INT_MIN, lowestDeviation = INT_MAX;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < nums.size(); i++) {
            int minimum = minimizeNumber(nums[i]);
            maxNum = max(maxNum, minimum);
            minHeap.push({minimum, max(nums[i], minimum * 2)}); // if original number is 1, we want to store 2
        }

        lowestDeviation = maxNum - minHeap.top().first;
        // now try to maximize the lowest numbers in the min heap, notice how all of your minimum 
        // numbers will be odd (math), we will multiply these numbers and keep track of the 
        // lowest deviation every time we multiply a number until one of these odd numbers turns into 
        // an even number
        while(true) {
            
           int minNum = minHeap.top().first;
           int originalNum = minHeap.top().second;
           minHeap.pop();


           lowestDeviation = min(lowestDeviation, maxNum - minNum);

           if(minNum < originalNum) {
               // we dont want the number being looked at to be greater than its original value
               // because if it were to be greater than the deviation would just be increasing
                minHeap.push({minNum * 2, originalNum});
                maxNum = max(maxNum, minNum * 2);

           } else {
               break;
           }


        }

        return lowestDeviation;
        


    }
};
