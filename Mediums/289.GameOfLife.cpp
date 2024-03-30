class Solution {
private:
    vector<pair<int, int>> dead_to_alive;
    vector<pair<int, int>> alive_to_dead;

public:
    /*
    Problem:
        According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
        The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its 
        eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article): Any live cell with fewer than two live neighbors dies as if caused by under-population.
        Any live cell with two or three live neighbors lives on to the next generation. Any live cell with more than three live neighbors dies, as if by over-population. Any dead cell with exactly three live 
        neighbors becomes a live cell, as if by reproduction. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
        Given the current state of the m x n grid board, return the next state.
    */
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();

        // decide future of each cell, not updating the board, but saving the dead->alive and alive->dead
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                decideFuture(board, i, j);
            }
        }

        // bring the dead back to life
        for(const auto& alive : dead_to_alive) {
            board[alive.first][alive.second] = 1;
        }

        // hold a funeral for the people that lost their lives
        for(const auto& dead : alive_to_dead) {
            board[dead.first][dead.second] = 0;
        }
    }

    // helper function to decide whether we change a 0 -> 1 or 1 -> 0
    void decideFuture(vector<vector<int>>& board, int i, int j) {

        int neighbors = 0;
        // first count the neighbors
        for (int x = max(0, i - 1); x <= min(i + 1, (int)board.size() - 1); x++) {
            for (int y = max(0, j - 1); y <= min(j + 1, (int)board[0].size() - 1); y++) {
                if (x == i && y == j) continue;
                neighbors += board[x][y];
            }
        }

        // next decide the current cell's future
        if(board[i][j] == 0 && neighbors == 3) {
            dead_to_alive.push_back({i, j});
        }

        if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
            alive_to_dead.push_back({i, j});
        }
    }
};
