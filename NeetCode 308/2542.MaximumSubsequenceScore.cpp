class Solution {
public:

    /*
        Problem:
          You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
          For chosen indices i0, i1, ..., ik - 1, your score is defined as: The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2. 
          It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]). Return the maximum possible score.
          A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.
          
        Approach:
        - first we want to sort the numbers in nums2 into descending order, but since we need to
            keep track of the corresponding index in nums1 we need to sort a list of pairs
        - the first number in each pair is the number in nums2 and the second number in the
            pair is the number in nums1
        - next calculate the scores, we already know the order of the numbers in nums2, know we 
            need to try and maximize the numbers we look at in nums1
        - to do this we can use a MIN heap (not max), in order to get rid of the lowest number
            in nums1

    */

    // sort a list of pairs based on first parameter
    static bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        
        // build list of pairs
        int n = nums1.size();
        vector<pair<int, int>> pairs (nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            pairs[i] = {nums2[i], nums1[i]};
        }

        // sort the list of pairs
        sort(pairs.begin(), pairs.end(), comparePairs);

        // calculate the max score
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long nums1Sum = 0, score = LONG_MIN;

        for(int i = 0; i < pairs.size(); i++) {
            // add numbers in nums1 to running sum and min heap
            nums1Sum += pairs[i].second;
            minHeap.push(pairs[i].second);

            if(minHeap.size() == k) {
                int nums2Min = pairs[i].first; // pairs is already sorted, min is current index
                int nums1Min = minHeap.top(); // lower number in nums1 is top of heap
                score = max(score, nums1Sum * nums2Min);

                // keep subsequent of length k
                minHeap.pop(); 
                nums1Sum -= nums1Min;
            }

        }

        return score;
    }
};
