class Solution {
public:

    /*
    Problem:
        Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.  
        Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), 
        where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
    
    */
    vector<vector<bool>> visited;
    // helper function to find all connecting "X's", starting from an X
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] == '.') {
            return;
        }

        visited[i][j] = true;

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }


    /*
    We will run a DFS whenever we land on an X that has not been found. Whenever this occurs
    we will find all conneted X's and mark them as visited. After each time we call our dfs
    function, we can increment the battleship number. Repeat this process everytime we find
    an X that has not been visited
    */
    int countBattleships(vector<vector<char>>& board) {
        // initialize variables, visited vector
        int battleships = 0;
        int n = board.size(), m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        // traverse through the board, calling our DFS whenever necessary
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'X' && !visited[i][j]) {
                    dfs(board, i, j);
                    battleships++;
                }
            }
        }

        return battleships;
    }
};
