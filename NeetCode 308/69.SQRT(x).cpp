class Solution {
public:

/*
    Problem: 
        Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
        You must not use any built-in exponent function or operator. For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/
    int mySqrt(int x) {
        //instead of checking every number to see which one falls the closest to the square root of x, or the actual square root of x, we can perform binary search

        //we can do this beacuse, for example: if x = 16, we check 8 first, 8*8 = 64 > 16, so this means that we know that numbers 9-16 are not possible for our answer

        //this reduced the running time of the algorithmn from 0(n) to 0(log n)
//------------------------------------------------------------------------------------------//

        //declare pointers
        int min = 0, max = x;

        //perform a binary search
        while(min <= max) {

            //obtain middle value
            long long mid = (min + max) / 2;

            //comapare squared value to x, and move pointers accordingly
            if(mid * mid == x) {
                return mid;
            } else if (mid * mid > x) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        //if we do not find a perfect square, then our right pointer (max) will be in the position of the rounded down value of the square root of x
        return max;
    }

};
