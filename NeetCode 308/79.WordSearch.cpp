class Solution {
public:

    /*
        Problem:
            Given an m x n grid of characters board and a string word, return true if word exists in the grid.
            The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
            The same letter cell may not be used more than once.
        Approach:
            1. We will be implementing a backtracking algorithmn
            2. We can define a recursive function that takes in the board, the word we are looking
                for, the index of the word we are currently looking at, and the coordinates
                of the board we are currently looking at
            3. For every iteration, we need to "mark" the coordinates of the board, and check the 
                adjacent cells (left, right, up, down)
            4. If either 4 of these cells ever go out of bounds or are not the correct characters
                corresponding to the index of the world then we can return false. However, 
                if the index = size of the word then we know that we have found the  word in the board
            5. This means that if either searching left, right, up, or down is true, then 
                we can return true in our main function
            6. After searching adjacent characters, we need to backtrack by "unmarking", the current
                cell (setting it equal to the current index of the word we are looking for)
            7. lastly, we need to traverse through the board and run this recursive function
                wherever the current char = first char of the world becuase we dont know any information
                about where the world could start on the board
    */

    // helper recursive backtracking function
    bool findWord(vector<vector<char>>& board, string word, int index, int row, int col) {

        // base cases
        // out of bounds or board[current cell] != word[current index] 
        if(row >= board.size() || col >= board[0].size() || board[row][col] != word[index] || row < 0 || col < 0) {
           return false;
        }

        // word found in the board
        if(index == word.size() - 1) {
            return true;
        }
       
        // "mark" the current cell
        board[row][col] = '3';
       
        // search adjacent cells
        bool found = (
            findWord(board, word, index + 1, row - 1, col) ||
            findWord(board, word, index + 1, row + 1, col) ||
            findWord(board, word, index + 1, row, col - 1) ||
            findWord(board, word, index + 1, row, col + 1)
        );

        // "unmmark" the current cell
        board[row][col] = word[index];
        return found;
        
    }


    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size(), m = board[0].size();

        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]){
                    if(findWord(board, word, 0, i, j)) {
                        // word found in board
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
