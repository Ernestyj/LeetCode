package leetcode51_60;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement,
 where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 每一个的横竖斜都没有其他皇后
 * Created by Eugene on 12/5/2015.
 */
public class NQueens {

    /**http://www.cnblogs.com/springfor/p/3870944.html
     * 回溯法 关键：每一行只能有一个皇后，用一维数组存每行皇后所在列。
     * 用一维数组则在回溯的时候不需进行remove重置操作，因为回溯正好就回到上一行，可以接着找下一个合法列坐标。
     * 走完最后一行，坐标（row，cols[row]）即皇后坐标。
     */
    public List<List<String>> solveNQueens(int n) {
        ArrayList<List<String>> res = new ArrayList<>();
        if(n<=0) return res;
        dfs(n, res, 0, new int[n]);
        return res;
    }
    private void dfs(int n, List<List<String>> res, int start, int[] cols){
        if(start==n){
            List<String> sol = new ArrayList<>(n);
            for(int i=0; i<n; i++){
                StringBuilder s = new StringBuilder();
                for(int j=0; j<n; j++){
                    if(j==cols[i]) s.append("Q");
                    else s.append(".");
                }
                sol.add(s.toString());
            }
            res.add(sol);
            return;
        }
        for(int i=0; i<n; i++){
            cols[start] = i;    //(start,i)
            if(isColCrossValid(start, cols)) dfs(n, res, start+1, cols);
        }
    }//判断列和对角线,对角线就是两点行差值和列差值是否相同
    private boolean isColCrossValid(int row, int[] cols){
        for(int r=0; r<row; r++){
            if(cols[row]==cols[r] || Math.abs(cols[row]-cols[r]) == Math.abs(row-r)) return false;
        }
        return true;
    }


    //简洁, 待理解
    public List<String[]> solveNQueens1(int n) {
        List<String[]> res = new ArrayList<>();
        helper(0, new boolean[n], new boolean[2*n], new boolean[2*n],
                new String[n], res);
        return res;
    }
    private void helper(int r, boolean[] cols, boolean[] d1, boolean[] d2,
                        String[] board, List<String[]> res) {
        if (r == board.length) res.add(board.clone());
        else {
            for (int c = 0; c < board.length; c++) {
                int id1 = r - c + board.length, id2 = 2*board.length - r - c - 1;
                if (!cols[c] && !d1[id1] && !d2[id2]) {
                    char[] row = new char[board.length];
                    Arrays.fill(row, '.'); row[c] = 'Q';
                    board[r] = new String(row);
                    cols[c] = true; d1[id1] = true; d2[id2] = true;
                    helper(r+1, cols, d1, d2, board, res);
                    cols[c] = false; d1[id1] = false; d2[id2] = false;
                }
            }
        }
    }

}
