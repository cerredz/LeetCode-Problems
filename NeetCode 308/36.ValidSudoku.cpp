class Solution {
public:
/*
    Problem:
        Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
        Each row must contain the digits 1-9 without repetition.
        Each column must contain the digits 1-9 without repetition.
        Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    Note:
      A Sudoku board (partially filled) could be valid but is not necessarily solvable.
      Only the filled cells need to be validated according to the mentioned rules.

------------------------------------------------------------------------------------------------
    Approach:
        1. We will have a set that keeps track of the unique numbers in each row, column, and 
            3x3 box
        2. We will traverse in row major order, we will add each number in each row to the set.
            if the set contains a duplicate we will return false. After every row, we can clear 
            the set and keep track of the number in the next row.
        3. We will repeat step 2, but instead of traversing in a row major order, we will 
            traverse in a column major order
        4. We will repeat step 2, but traverse every 3x3 boxes
        5. If control reaches outside all of the traversals, we then have a valid sudoku
            and can return true
------------------------------------------------------------------------------------------------
    Psuedocode:
    
    - declare a set for keeping track of unique numbers

    - for every row in board:
        - for every column in board:
            - if the current number is in the set already:
                - return false
            - insert the current number into the set
        - clear the set after every row
    
    - for every column in board:
        - for every row in board:
            - if the current number is in the set already:
                - return false
            -insert the current number into the set
        -clear the set after every column
    
    - for every 3x3 box in the board
        - if the current number is already in the set 
            - return false
        - insert the current number into the set
    - clear the set after every 3x3 box traversal

    - return true
       
**/
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int numRows = board.size();
        int numCols = board[0].size();
        //numRows and numCols are used to make code look cleaner

        unordered_set<char> s;

        //row major traversal
        for(int i = 0; i < numRows; i++)
        {
            
            for(int j = 0; j < numCols; j++)
            {
                if(board[i][j] != '.') {
                    if(s.count(board[i][j]) > 0) {//evaluates to true if we have a number appear more than once in a row
                        return false;
                    }
                    s.insert(board[i][j]);
                }

                
            }
            s.clear();//clear set after every row
        }

        //column major traversal
        for(int i = 0; i < numCols; i++) 
        {
            
            for(int j = 0; j < numRows; j++)
            {
                if(board[j][i] != '.') {
                    if(s.count(board[j][i]) > 0) {//evaluates to true if we have a number appear more than once in a column
                        return false;
                    }
                    s.insert(board[j][i]);
                }

                
            }
            s.clear();//clear set after every column
        }

        //3x3 box traversal
        for (int i = 0; i < numRows; i += 3) {
            for (int j = 0; j < numCols; j += 3) {
                
                for (int row = i; row < i + 3; row++) {

                    for (int col = j; col < j + 3; col++) {
                        if(board[row][col] != '.') {
                            if(s.count(board[row][col]) > 0) {//evaluates to true if we have a number appear more than once in a 3x3 box
                                return false;
                            }
                            s.insert(board[row][col]);
                        }
                    }
                   
                }
                s.clear();//clear set after every 3x3 box
            }
        }

        return true;
    }
};
