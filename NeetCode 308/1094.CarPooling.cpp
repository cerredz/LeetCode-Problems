class Solution {
public:
    /*
      Problem:
        There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
        You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers
        and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's 
        initial location. Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
    */
    // sort tuples based off middle value
    static bool customComparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; 
    }

    // sort heap of pairs into min heap based off first value
    static bool customPairComparator(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; 
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        

        // sort tuples in trips using the middle index
        sort(trips.begin(), trips.end(), customComparator);

        // store trips into min heap, first paramter = to(i), second parameter = capacity of trip
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&customPairComparator)> min_heap(customPairComparator);
        int n = trips.size(), curr_capacity = 0 ;

        for(int i = 0; i < n; i++) {

            int currentTripStart = trips[i][1];
            while(!min_heap.empty() && min_heap.top().first <= currentTripStart) {
                // 1 or more trips ended, remove capacity
                curr_capacity -= min_heap.top().second;
                min_heap.pop();
            }

            // add current trip to the min heap
            min_heap.push({trips[i][2], trips[i][0]});
            curr_capacity += trips[i][0];
            
            if(curr_capacity > capacity) return false;
        }
        return true;
    }
};
