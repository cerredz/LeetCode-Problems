class Solution {
public:

/*
    Problem:

      Given a positive integer num, return true if num is a perfect square or false otherwise.
      A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
      You must not use any built-in library function, such as sqrt.

    Approach:
        1. Instead of checking every number from 1 -> num to see if num has a perfect square
            we can use binary search to see if nums has a perfect square
        2. Initilize two pointers, one at 0, and one at num, and then perform a standard 
            binary search with these numbers where you are checking the squared value of the 
            middle number and comparing it to num
*/
    bool isPerfectSquare(int num) {

        //declare pointers
        int min = 0, max = num;

        //perform a binary search, comparing squared value of mid to num
        while(min <= max) {

            //store mid in 64-bit integer type
            long long mid = (min + max) / 2;

            
            if(mid * mid == num) { //found a perfect square for nums 
                return true;
            } else if (mid * mid > num) { // squared value is too big, decrease our max number
                max = mid - 1;
            } else { // squared value is too small, increase our min number
                min = mid + 1;
            }
        }

        //every possible number has been checked at this pointer by using binary search, if control reaches here then no perfect square has been found
        return false;
    }
};
