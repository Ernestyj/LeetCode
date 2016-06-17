package leetcode51_60;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 For example,
 Given the following matrix:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
 * Created by DCLab on 12/7/2015.
 */
public class SpiralMatrix {

    /**https://leetcode.com/discuss/12228/super-simple-and-easy-to-understand-solution
     * 此思路不易出错
     * @param matrix
     * @return
     */
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix.length == 0) return res;
        int m = matrix.length-1, n = matrix[0].length-1;    //end
        int r = 0, c = 0;   //begin
        while (r<=m && c<=n) {
            for (int j = c; j <= n; j++) res.add(matrix[r][j]);// Traverse Right
            r++;
            for (int i = r; i <= m; i++) res.add(matrix[i][n]);// Traverse Down
            n--;
            if (r<=m) {   // Traverse Left TODO
                for (int j = n; j >= c; j--) res.add(matrix[m][j]);
            }
            m--;
            if (c<=n) {   // Traver Up TODO
                for (int i = m; i >= r; i--) res.add(matrix[i][c]);
            }
            c++;
        }
        return res;
    }

    /**
     * 若只剩下一行/列，则只处理此行/列，其余按circle方式处理
     * http://www.programcreek.com/2013/01/leetcode-spiral-matrix-java/
     * @param matrix
     * @return
     */
    public ArrayList<Integer> spiralOrder1(int[][] matrix) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        if(matrix == null || matrix.length == 0) return result;
        int m = matrix.length;
        int n = matrix[0].length;
        int x=0;
        int y=0;
        while(m>0 && n>0){
            if(m==1){//if one row/column left, no circle can be formed
                for(int i=0; i<n; i++) result.add(matrix[x][y++]);
                break;
            }else if(n==1){
                for(int i=0; i<m; i++) result.add(matrix[x++][y]);
                break;
            }
            //below, process a circle
            for(int i=0;i<n-1;i++) result.add(matrix[x][y++]);//top - move right
            for(int i=0;i<m-1;i++) result.add(matrix[x++][y]);//right - move down
            for(int i=0;i<n-1;i++) result.add(matrix[x][y--]);//bottom - move left
            for(int i=0;i<m-1;i++) result.add(matrix[x--][y]);//left - move up
            x++;
            y++;
            m=m-2;
            n=n-2;
        }
        return result;
    }

}
