
/**Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement,
 where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 每一个的横竖斜都没有其他皇后
 * Created by Eugene on 12/5/2015.
 */
class Solution {
public:
     /** 回溯法 关键：每一行只能有一个皇后，用一维数组存每行皇后所在列。
     * 用一维数组则在回溯的时候不需进行remove重置操作，因为回溯正好就回到上一行，可以接着找下一个合法列坐标。
     * 走完最后一行，坐标（row，cols[row]）即皇后坐标。
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queenCol(n, -1);
        dfs(0, queenCol, res);
        return res;
    }
    void dfs(int row, vector<int>& qCol, vector<vector<string>>& res) {
        int n = qCol.size();
        if (row == n) {
            vector<string> out(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                out[i][qCol[i]] = 'Q';
            }
            res.push_back(out);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValid(qCol, row, i)) {
                qCol[row] = i;
                dfs(row + 1, qCol, res);
                qCol[row] = -1;
            }
        }
    }
    bool isValid(vector<int>& qCol, int row, int col) {//判断列和对角线,对角线就是两点行差值和列差值是否相同
        for (int i = 0; i < row; ++i) {
            if (col == qCol[i] || abs(row - i) == abs(col - qCol[i])) return false;
        }
        return true;
    }
};

/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 Empty cells are indicated by the character '.'.
 You may assume that there will be only one unique solution.
 * Created by DCLab on 11/20/2015.
 */
class Solution {
public:
    //跟此题类似的有 Permutations 全排列，Combinations 组合项， N-Queens N皇后问题等等，其中尤其是跟 N-Queens N皇后问题的解题思路及其相似
    //对于每个需要填数字的格子带入1到9，每代入一个数字都判定其是否合法，如果合法就继续下一次递归，结束时把数字设回'.'
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
    bool dfs(vector<vector<char>>& board){
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j]=='.'){
                    for (char ch='1'; ch<='9'; ch++){
                        board[i][j] = ch;
                        if (isValidSudoku(board, i, j)){    //限制条件
                            if (dfs(board)) return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board, int x, int y) {   //x,y为坐标
        int i, j;
        for (i = 0; i<9; ++i) {   // Same value in the same i?
            if (x!=i && board[i][y]==board[x][y]) return false;
        }
        for (j = 0; j<9; ++j) {   // Same value in the same j?
            if (y!=j && board[x][j]==board[x][y]) return false;
        }
        //TODO 注意如何计算所在3*3 block的起始行号/列号
        for (i = (x/3)*3; i < (x/3+1)*3; ++i) {   // Same value in the 3 * 3 block it belong to?
            for (j = (y/3)*3; j < (y/3+1)*3; ++j) {
                if (x!=i && y!=j && board[i][j]==board[x][y]) return false;
            }
        }
        return true;
    }
};