class Solution {
public:

/*
  Problem:
      You are given a 0-indexed array maxHeights of n integers.
      You are tasked with building n towers in the coordinate line. The ith tower is built at coordinate i and has a height of heights[i].
      A configuration of towers is beautiful if the following conditions hold:
      1 <= heights[i] <= maxHeights[i] heights is a mountain array.Array heights is a mountain if there exists an index i such that:
      For all 0 < j <= i, heights[j - 1] <= heights[j] For all i <= k < n - 1, heights[k + 1] <= heights[k] Return the maximum possible sum of heights of a beautiful configuration of towers.
*/
    long long maximumSumOfHeights(vector<int>& maxHeights) {

        // for every index in the vector, keep track of the left lowest and right lowest index. Having a running current sum that you add the left and right lowest indexes to, and after every iteration compare this current
        // sum to a global max sum variables

        // declare max height and current height
        long long maxHeight = 0, currentHeight = 0;

        // iterate through every element in maxHeights
        for(int i = 0; i < maxHeights.size(); i++) {

            // keep track of the current height, left lowest index, and right lowest index
            currentHeight = maxHeights[i];
            long long leftLowest = maxHeights[i], rightLowest = maxHeights[i];
            
            // finding and adding left lowest index to the current height
            for(int j = i - 1; j >= 0; j--) {
                if(maxHeights[j] < leftLowest) leftLowest = maxHeights[j];
                currentHeight += leftLowest;
            }

            //finding and adding the right lowest index to the current height
            for(int k = i + 1; k < maxHeights.size(); k++) {
                if( maxHeights[k] < rightLowest) rightLowest = maxHeights[k];
                currentHeight += rightLowest;
            }

            // compare height at current iteration to max height
            maxHeight = max(maxHeight, currentHeight);
        }
        
        return maxHeight;
    }
};
