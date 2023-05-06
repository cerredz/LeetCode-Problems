class Solution {
public:

/*

    Problem:
    
        You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum
        weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
        Return the minimum number of boats to carry every given person.
----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer approach starting at the leftmost and rightmost
            indexes.
        2. First we must sort the vector, that way when we increment our pointers we know for 
            a 100 percent fact that we are either increasing or decreasing the values that 
            we are looking
        3. We will keep iterating until our left pointer is greater than our right pointer,
            and we will be simulating an increase in the number of boats needed in every 
            iteration
        4. If the number[leftPointer] + number[rightPointer] is less than the limit this means
            that the two number can fit into one boat, so increment the left pointer, and 
            decrement the right pointer to simulate both indexes counting as one boat
        5. If the number[leftPointer] + number[rightPointer] is not less than the limit,
            this means  that the number at the right pointer is to big to be paired with the
            number at the left pointer, so simulate putting the number[rightPointer] into a
            boat by itself, and do not touch the left pointer
        6. Increment the number of boats by 1 after every iteration
        7. Return the number of boats
-----------------------------------------------------------------------------------------------
    Psuedocode:

    - declare left pointer, right pointer, and res variable

    - while leftPointer <= rightPointer:

        - if people[leftPointer] + people[rightPointer] <= the limit:
            - increment the left pointer
            - decrement the right pointer

        - else if people[leftPointer] + people[rightPointer] > the limit:
            - only decrement the rigth pointer
        
        - no matter what, increment the res variable
    
    - return res vaiable
-----------------------------------------------------------------------------------------------

*/
    int numRescueBoats(vector<int>& people, int limit) {
        
        //initialize pointers and res variable
        int leftPointer = 0, rightPointer = people.size() - 1, numBoats = 0;

        //sort the vector
        sort(people.begin(), people.end());

        //keep iterating until our pointer cross
        while(leftPointer <= rightPointer) {

            //increment left pointer if two numbers can fit into a boat
            if (people[leftPointer] + people[rightPointer] <= limit) {
                leftPointer++;
            }

            //decrement right pointer and increment num boats
            rightPointer--;
            numBoats++;
        }

        return numBoats;

        
    }
};
