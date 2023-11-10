class Solution {
public:

    /*

        Problem:
          Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
          A region is captured by flipping all 'O's into 'X's in that surrounded region.

        Approach:
            1. Notice how all the zeros on the border of the board should not be flipped
            2. Any adjacent zeros next to the zeros on the board should also not be flipped
            3. Our goal will be to work our way inwards, and "mark" all of the zeros that connect
                to a zero on the border
            4. Any zero that does not connect to a zero on the border we will flip it to an x
    */

    // helper function to check zeros that connect to the border
    void dfs(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visited_zeros) {

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == 'X' || visited_zeros[row][col]) {
            return;
        }

        visited_zeros[row][col] = true;
        
        dfs(board, row + 1, col, visited_zeros);
        dfs(board, row - 1, col, visited_zeros);
        dfs(board, row, col + 1, visited_zeros);
        dfs(board, row, col - 1, visited_zeros);
    }

    void solve(vector<vector<char>>& board) {
        
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited_zeros(n, vector<bool> (m, false));

        // traverse inward from left and right border
        for(int i = 0; i < n; i++) {
            dfs(board, i, 0, visited_zeros);
            dfs(board, i, m - 1, visited_zeros);
        }

        // traverse inwward from top and bottom border
        for(int i = 0; i < m; i++) {
            dfs(board, 0, i, visited_zeros);
            dfs(board, n - 1, i, visited_zeros);
        }

        // flip all the non-visited zeros into x's
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j++) {
                cout << visited_zeros[i][j] << ",";
                if(board[i][j] == 'O' && !visited_zeros[i][j]) {
                    board[i][j] = 'X';
                }
            }

            cout << endl;
        }


    }
};
