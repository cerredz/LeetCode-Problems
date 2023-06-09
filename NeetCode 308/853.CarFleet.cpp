class Solution {
public:
/*

    There are n cars going to the same destination along a one-lane road. The destination is target miles away.
    You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).
    A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed.
    The distance between these two cars is ignored (i.e., they are assumed to have the same position).
    A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.
    If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
    Return the number of car fleets that will arrive at the destination.
----------------------------------------------------------------------------------------------
    Approach:
        1. For this problem we will first combine the two vectors into one vector with a pair as 
            the indexes. Where the first parameter is the position of the car, and the second
            parameter is the time is takes for that car to reach the target
        2. We will keep track of the maximum finish time of the cars crossing the finish line, and also 
            keep track of the cars that form a new fleet
        2. We will iterate through this new vector in descending position values, if the finish time of 
            the current car is greater than the maximum finishing time so far, this means that this car 
            belongs to a new fleet of cars, so we can  increment the result and update the maxTime
        3. All of the finishing times that are not greater than the maxTime means that they belong in the
            same fleet of cars, so we do nothing when this happens.
        4. Return the result
---------------------------------------------------------------------------------------------

*/
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        //first parameter is position, second parameter is finishing time
        vector<pair<int,double>> startingGrid;

        //merge two vectors into one
        for(int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            startingGrid.push_back({position[i], time});
        }

        //sort position times into descending order
        sort(startingGrid.begin(), startingGrid.end(), greater<pair<int,int>>());
        
        //keep track of max time per fleet, and number of fleets
        double maxTime = 0.0;   
        int result = 0;

        for(int i = 0; i < position.size(); i++) {

            //get finishing time of current car
            double finishTime = startingGrid[i].second;
            
            
            if(finishTime > maxTime) {
                //car belongs to new fleet is control reaches here, update maxTime and result
                maxTime = finishTime;
                result++;
            }

        }

        return result;
    }
};
