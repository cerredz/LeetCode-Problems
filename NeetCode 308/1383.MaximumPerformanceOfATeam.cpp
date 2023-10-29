class Solution {
public:

    /*
        Problem:
          You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. 
          speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
          Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
          The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.
          Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.
          
        Approach:
        // sort speed and efficentcy into pairs, sorted based off of efficiency
        // iterate through efficientcy, adding the speeds into a min heap
        // and keeping a running some of the speed
        // if we already have k engineers, remove the lowest speed from the min heap
        // and subtract from the running speed
        // calculate the performance after evey iteration and keep track of the 
        // highest performance

    */
    // sort pairs into descending order based off first value
    static bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        

        // sort speed and efficiency pairs based off speed
        vector<pair<int, int>> sortedPairs(n);
        for(int i = 0; i < n; i++) {
            sortedPairs[i] = {efficiency[i], speed[i]};
        }
        sort(sortedPairs.begin(), sortedPairs.end(), comparePairs);

        // use a min heap to calculate the maximum performance (first parameter = speed, second parameter = index of the pair in sortedPairs(used to decrement speed in running sum))
        long long maxPerformance = 0, speedSum = 0;
        priority_queue <int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++) {

            int speed = sortedPairs[i].second;
            speedSum += speed;
            pq.push(speed);

            if(pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }

            int minEfficiency = sortedPairs[i].first;
            maxPerformance = max(maxPerformance, speedSum * minEfficiency);
        }

        int MOD = 1e9 + 7;
        return maxPerformance % MOD;

    }
};
