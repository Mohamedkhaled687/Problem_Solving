class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> col, posDiag, negDiag;
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        // Backtracking function
        function<void(int)> backtrack = [&](int r) {
            if (r == n) {
                res.push_back(board);
                return;
            }

            for (int c = 0; c < n; ++c) {
                if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) 
                    continue;
                
                // Place the queen
                col.insert(c);
                posDiag.insert(r + c);
                negDiag.insert(r - c);
                board[r][c] = 'Q';

                // Recur for the next row
                backtrack(r + 1);

                // Remove the queen (backtrack)
                col.erase(c);
                posDiag.erase(r + c);
                negDiag.erase(r - c);
                board[r][c] = '.';
            }
        };
        
        backtrack(0);
        return res;
    }
};
