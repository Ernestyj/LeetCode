package leetcode51_60;

import java.util.ArrayList;
import java.util.List;

/**
 * Follow up for N-Queens problem.
 Now, instead outputting board configurations, return the total number of distinct solutions.
 * Created by Eugene on 12/5/2015.
 */
public class NQueensII {


    private int count = 0;
    /**
     * http://www.cnblogs.com/springfor/p/3870944.html
     * 回溯法
     * 关键：每一行只能有一个皇后，用一维数组存每行皇后所在列。
     * 用一维数组则在回溯的时候不需进行remove重置操作，因为回溯正好就回到上一行，可以接着找下一个合法列坐标。
     * 走完最后一行，坐标（row，colVal[row]）即皇后坐标。
     * @param n
     * @return
     */
    public int totalNQueens(int n) {
        if (n <= 0) return 0;
        int [] colVal = new int[n];
        dfsHelper(n, 0, colVal);
        return count;
    }
    private void dfsHelper(int n, int row, int[] colVal){
        if(row == n){
            count++;
        }else{
            for(int i = 0; i < n; i++){
                colVal[row] = i;    //(row,i)
                if(isValid(row, colVal)) dfsHelper(n, row + 1, colVal);
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
