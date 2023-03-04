class Solution {
public:

/*
    Problem:
      You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, 
      heighti] denotes the width and height of the ith rectangle.Two rectangles i and j (i < j) are considered interchangeable 
      if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj 
      (using decimal division, not integer division).

      Return the number of pairs of interchangeable rectangles in rectangles.
------------------------------------------------------------------------------------------------------------------
    Approach:
        1. Store the width-to-height ratio of each ordered pair in a map, with the width-to-height ratio as the 
            key, and the number of pair with the same width-to-height ratio as the value
        2. Loop through all the entries in the map,  increment result by n * (n-1) / 2, where n is the size of the 
            current entry
            //the equation n * (n-1) / 2 account for all possible interchangeable pairs of size n
        3. return result
-----------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare map and res 
        - for each pair in rectangles:
            - increment map[width-to-height ratio] by 1
        
        - for every entry in the map:
            - n = entry.second
            - res += n * (n-1) / 2
        
        - return res
*/
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        //map to store width-to-height ratios
        unordered_map<long double, int> map; 

        for(int i = 0; i < rectangles.size(); i++){
            //calculate width-to-height ratio and increment map
            map[static_cast<long double>(rectangles[i][0]) / static_cast<long double>(rectangles[i][1])]++;
        }

        long long res = 0;
        for(auto entry : map) {
            //calculate number of interchangeable rectangle for every entry and increment res
            res += ((long long)entry.second * (entry.second - 1) / 2);
        }
        return res;
    }
};
