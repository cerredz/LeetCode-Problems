class Solution {
public:
    /*
        Problem:
        Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
        Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons 
        from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
        Return the minimum time Bob needs to make the rope colorful.



        Sliding window approach: keep track of the total group cost of the same adjacent 
        balloon colors, when we reach a new color, we DONT need to sort the neededTimes
        found, but ONLY need to delete the MAXIMUM time found beacuse if there are 
        n of the same adjacent color balloons, we will always be adding n-1 times
        onto the res. 
    */

    int minCost(string colors, vector<int>& neededTime) {
        
        int totalCost = 0, groupCost = 0, groupMax = 0;

        for(int i = 0; i < colors.length(); i++) {
            if(i > 0 && colors[i] != colors[i - 1]) {
                // new colors has been found
                totalCost += groupCost - groupMax;
                groupCost = 0;
                groupMax = 0;
            }

            // keep track of group (same color), cost and most needed time found
            groupCost += neededTime[i];
            groupMax = max(groupMax, neededTime[i]);
        }

        totalCost += groupCost - groupMax;
        return totalCost;
    }
};
