class Solution {
public:

/* 

    Problem:
      Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
      The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
      You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

    Approach:
        1. Notice how we have to compare all of our points to the origin, which means that x2 and y2 
            will always be zero. This means that for every ordered pair in points sqrt(x1^2 + x2^2)
            will represent how close the point is to the origin
        2. Since we need to return the k-closest points, we can store sqrt(x1^2 + x2^2 in a priority queue  
            for every point while also keep tracking of the index of the point in points, that we 
            we can directly access the ordered pair when getting the k-closest points from the 
            origin
        3. After storing all sqrt(x1^2 + x2^2) in a priority queue, we simply just iterate k time over the 
            priority queue adding the top ordered pair to a 2d array
*/

    // change the max heap to a min heap
    struct ComparePairs {
        bool operator()(const pair<double, int>& p1, const pair<double, int>& p2) {
            return p1.first > p2.first; 
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> res;
        priority_queue<pair<double, int>, vector<pair<double, int>>, ComparePairs> minHeap;

        // store the distance from each of the points to the origin into the min heap
        for(int i = 0; i < points.size(); i++) {
            double dist = (double)sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            minHeap.push({dist, i});
        }

        // add the k-closest points to the 2d array
        while(k > 0) {
            pair<double,int> closestPoint = minHeap.top();
            res.emplace_back(points[closestPoint.second]);
            minHeap.pop();
            k--;
        }

        // return the 2d array
        return res;



    }
};
