class Solution {
public:

/*
    Problem: 
    You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
    Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, 
    return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
    --------------------------------------------------------------------------------------------
    Approach: 
        - we are going to be loopng through the vector and checking 3 indexes at a time, if
            they are all zero we are going to increment our availablePlots counter, and insert
            a 1 in the middle of the 3 0's
        - at the end, if our availablePlots counter is >= n, then we can return true, otherwise
            false
    --------------------------------------------------------------------------------------------
    Psuedocode
    - declare availablePlots counter
    // an edge case we have is it the vector is only a size of 1
    - if vector is of size 1
        - if the number is 0
            - increment availablePlots
    
    - if the vector is bigger than size 1
        - for each number in flowerbed:
            - if we encounter 3 zeros in a row
                - set middle 0 to 1
                - increment availablePlots
    
    - return availablePlots >= n

*/
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int availablePlots = 0;

        // 2 cases, if size of vector is 1 or greater than 1

         if(flowerbed.size() == 1){//first case
           
           if(flowerbed[0] == 0) {
               flowerbed[0] = 1;
               availablePlots++;
           }

        }else{//second case
            //before looping through the vector, we must check if the first two numbers are zeros
                //because i-1 at index 0 will give us an out of bounds error
            if(flowerbed[0] == 0 && flowerbed[1] == 0) {
                flowerbed[0] = 1;
                availablePlots++;
            }

            for(int i = 1; i < flowerbed.size() - 1; i++) {
                if(flowerbed[i-1] != 1 && flowerbed[i] != 1 && flowerbed[i + 1] != 1) {
                    flowerbed[i] = 1;//must update vector to ensure correct number of available plots
                    availablePlots++;
                }
            }
            //after looping through the vector, we must check if the last two numbers are zeros
                //because i + 1 at the last index will also give us an out of bounds error
            if(flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0){
                availablePlots++;
            }
        }
        
        return availablePlots >= n;
    }
};
