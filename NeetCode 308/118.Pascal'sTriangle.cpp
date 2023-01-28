class Solution {
public:

/*
    Approach: 
    - we will be looping through the triangle and updating the values as we loop through

    - declare result vector
    - for every row < numRows :
        - declare temp vector (row)

        - for every number in each row :
            - if j = 0 or j = i 
                // this means that we are either at the farmost left or farmost right of each row
                - add 1 to row vector
            - else
                - add the two numbers in the previous row where the two numbers indexes are
                    j and j-1
        
        - add the row vector to the result vector

    - return result vector
            

*/
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;

        for(int i = 0; i < numRows; i++) {
            vector<int> row;

            for(int j = 0; j <= i; j++) {

                // 2 cases, farmost value or not
                if(j == 0 || j == i) {//farmost value checker
                    row.emplace_back(1);
                }else {//number is in the middle, and must add 2 numbers together
                    row.emplace_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            res.emplace_back(row);//push row onto vector of vector
        }
        return res;
    }
};
