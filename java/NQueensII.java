package leetcode51_60;

/**
 * Follow up for N-Queens problem.
 Now, instead outputting board configurations, return the total number of distinct solutions.
 * Created by Eugene on 12/5/2015.
 */
public class NQueensII {

    /**
     * http://www.cnblogs.com/springfor/p/3870944.html
     * 回溯法,与NQueens解法几乎一样
     * 关键：每一行只能有一个皇后，用一维数组存每行皇后所在列。
     * 用一维数组则在回溯的时候不需进行remove重置操作，因为回溯正好就回到上一行，可以接着找下一个合法列坐标。
     * 走完最后一行，坐标（row，cols[row]）即皇后坐标。
     * @param n
     * @return
     */
    private int count = 0;  //TODO count必须作为全局或成员变量,不能作为传参
    public int totalNQueens(int n) {
        if (n<=0) return 0;
        int[] cols = new int[n];
        dfsHelper(n, 0, cols);
        return count;
    }
    private void dfsHelper(int n, int row, int[] cols){
        if(row==n){
            count++;
            return;
        }
        for(int i=0; i<n; i++){
            cols[row] = i;    //(row,i)
            if(isColCrossValid(row, cols)) dfsHelper(n, row + 1, cols);
        }
    }
    //判断列和对角线,对角线就是两点行差值和列差值是否相同
    private boolean isColCrossValid(int row, int[] cols){
        for(int r=0; r<row; r++){
            if(cols[row]==cols[r] || Math.abs(cols[row]-cols[r]) == Math.abs(row-r))
                return false;
        }
        return true;
    }

}
