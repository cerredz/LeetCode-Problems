class Solution {
public:

/*
  Problem:
    You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
    Return the intersection of these two interval lists. A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
    The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

*/
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        

        int n = firstList.size(), m = secondList.size();
        int first = 0, second = 0; // two pointers
        vector<vector<int>> res;

        if(firstList.empty() || secondList.empty()) return res; // edge case

        while(first < n && second < m) {
            
            // get the intersection of both lists
            int left = max(firstList[first][0], secondList[second][0]);
            int right = min(firstList[first][1], secondList[second][1]);

            if(left <= right) {
                res.push_back({left, right});
            }
        
            (firstList[first][1] < secondList[second][1]) ? first++ : second++; // slide the window based off lower value

        }

        return res;
    }
};
