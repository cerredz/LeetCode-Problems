class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // record where we need to use the ladder, and sort the height in increasing order using a heap
        int n = heights.size();
        priority_queue<int> heap;
        for(int i = 0;  i < n - 1; i++) {
            int diff = heights[i] - heights[i + 1];
            if(diff < 0) {
                heap.push(abs(diff));
                bricks -= abs(diff); // try to use bricks first for everything

                // not enough bricks, use our ladders, but for the biggest jumps, hence why we use a max heap
                if(bricks < 0) {
                    if(ladders > 0) {
                        ladders -= 1;
                        bricks += heap.top();
                        heap.pop();
                    } else {
                        // no more bricks or ladders, return index we made it to
                        return i;
                    }
                }
               
            }
        }

        return n - 1;
    }
};
