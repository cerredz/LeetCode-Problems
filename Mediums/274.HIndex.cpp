class Solution {
public:
    /*
        Problem:
        Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
        According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that 
        have each been cited at least h times.


        Approach:
            1. we can use binary search, where the size of citations is the right bound of the binary 
                search. The logic behind this is if citations is 5 elements in size, then it is impossible
                to have an h-index greater than 5
    */

    // checks if an inputted index is a valid h index
    bool checkHIndex(int h, vector<int>& nums) {
        int count = 0;
        for(const int& i : nums) {
            if(i >= h) count++;
        }
        return count >= h;
    }
    int hIndex(vector<int>& citations) {

        // declare bounds for binary search
        int left = 0, right = citations.size();
        int max_h_index = 0;

        // perform binary search
        while(left <= right) {
            int mid = (left + right) / 2;

            if(checkHIndex(mid, citations)) {
                max_h_index = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return max_h_index;
    }
};
