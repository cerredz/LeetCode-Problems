class Solution {
public:

/*
    Problem:
        Given an integer array nums and an integer k, return the kth largest element in the array.
        Note that it is the kth largest element in the sorted order, not the kth distinct element.
        Can you solve it without sorting?
        
    Approach:
        1. Insert all of the elements in nums into a max heap (priority_queue), then pop from the max
            heap k - 1 times and return the top of the max heap
*/
    int findKthLargest(vector<int>& nums, int k) {
        
        // insert all elements in nums into a max heap
        priority_queue<int> heap;
        for(int i : nums) heap.push(i);

        // pop from the heap k-1 times
        while(k > 1) {
            heap.pop();
            k--;
        }
        return heap.top();
    }
};
