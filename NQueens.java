package leetcode51_60;

import java.util.ArrayList;
import java.util.List;

/**
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement,
 where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 每一个的横竖斜都没有其他皇后
 * Created by Eugene on 12/5/2015.
 */
public class NQueens {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        System.out.println();
    }

    /**
     * http://www.cnblogs.com/springfor/p/3870944.html
     * 回溯法
     * 关键：每一行只能有一个皇后，用一维数组存每行皇后所在列。
     * 用一维数组则在回溯的时候不需进行remove重置操作，因为回溯正好就回到上一行，可以接着找下一个合法列坐标。
     * 走完最后一行，坐标（row，colVal[row]）即皇后坐标。
     * @param n
     * @return
     */
    public List<List<String>> solveNQueens(int n) {
        ArrayList<List<String>> res = new ArrayList<>();
        if(n <= 0) return res;
        int [] colVal = new int[n];
        dfsHelper(n, res, 0, colVal);
        return res;
    }
    private void dfsHelper(int n, List<List<String>> res, int row, int[] colVal){
        if(row == n){
            List<String> aSolution = new ArrayList<>(n);
            for(int i = 0; i < n; i++){
                StringBuilder s = new StringBuilder();
                for(int j = 0; j < n; j++){
                    if(j == colVal[i]) s.append("Q");
                    else s.append(".");
                }
                aSolution.add(s.toString());
            }
            res.add(aSolution);
        }else{
            for(int i = 0; i < n; i++){
                colVal[row] = i;    //(row,i)
                if(isValid(row, colVal)) dfsHelper(n, res, row + 1, colVal);
            }
        }
    }
    //对角线的判断就是两点行差值和列差值是否相同
    private boolean isValid(int row, int [] colVal){
        for(int i = 0; i < row; i++){
            if(colVal[row] == colVal[i] || Math.abs(colVal[row] - colVal[i]) == Math.abs(row - i))
                return false;
        }
        return true;
    }

}
