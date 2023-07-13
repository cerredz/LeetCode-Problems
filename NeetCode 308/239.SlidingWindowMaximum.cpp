class Solution {
public:

/*

    Problem:
      You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
      You can only see the k numbers in the window. Each time the sliding window moves right by one position.
      Return the max sliding window.
----------------------------------------------------------------------------------------------
    Approach:
        1. This questions is clearly a sliding window problem, but in order to solve it 
            we wil need both a max variable and a heap that takes in pairs. The first parmeter
            of the pair stores the numbers in nums, and the second parameter stores
            the indexes of these numbers.
        2. The reason why we need to store the indexes of the numbers is in the case where 
            we need to find the second biggest number in the window. For example, 
            if the number at the leftmost point of our window is the largest, then 
            the next iteration we will have to find the next closest number to this previous
            large number.
        3. Beacuse a max heap already takes care of storing numbers from largest to smallest,
            we can just pop from our heap until we have a number that is in the index
            of the current window. Once we find a number that has an index that is in the
            current window, this is the new max.
        4. If we run into a number that is bigger than the max, then we simple just update our
            max, push this number onto the res vector, and store the number and index in the
            heap
        5. If the previous leftmost index of our window was not that max, and the next number
            is not bigger than our max, then we simple just add max to the res vector
        6. Return the res vector

    Psuedocode:
        
        - declare vector (res), max heap (heap), and max variable (max)

        - for the first k numbers in nums:
            - keep track of max number
            - push number and index of number onto the heap
        
        - add the max to res

        - for each number in nums from indexes k->nums.size()

            - add number and index onto heap

            - if we run into a bigger number than max
                - update max
                - push max onto res

            - else if previous leftmost index was our max
                - keep popping from the top of our keep until we get a number that is in the 
                    current window
                - set max to the heap.top().first
                - push max onto res

            - else
                - push max onto res 
*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        

        //declare vector, max heap, and max variable
        vector<int> res;
        priority_queue<pair<int,int>> heap;//first param = number, second param = index
        int max = -100000;

        //obtain max of first k-elements, and store first k-elements into the heap
        for(int i = 0; i < k; i++) {
            if(nums[i] > max) {
                max = nums[i];
            }
            heap.push({nums[i], i});

        }

        //push current max onto res
        res.push_back(max);

        
        for(int i = k; i < nums.size(); i++) {
            
            //always store current number into heap
            heap.push({nums[i], i});

            //case 1: new max found
            if(nums[i] > max) {
                max = nums[i];
            } 

            //case 2: previous leftmost index was our max variable, now must find largest variable in the window
            else if (nums[i - k] == max) {
               
                while(!heap.empty() && heap.top().second <= i - k) { //heap stores numbers in biggest to smallest, so we only have to check if the number at the top is within the range of the window
                        heap.pop();
                    }
                    if(heap.empty()) {
                        max = nums[i];
                    } else {
                        //top of heap will be in bounds of the window, and our largest number
                        max = heap.top().first;
                    }
            }

            //case 3: no new max and previous leftmost index was not that max, in this case we just push onto stack, just like the other cases
            res.push_back(max);
        }

        return res;
    }
};
