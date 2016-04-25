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

    public static void main(String[] args) {
        int[][] matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        System.out.println("*****RESULT*****");
        List<Integer> result = new SpiralMatrix().spiralOrder(matrix);
        for (Integer i : result) System.out.print(i + " ");
    }

    /**
     * 若只剩下一行/列，则只处理此行/列，其余按circle方式处理
     * http://www.programcreek.com/2013/01/leetcode-spiral-matrix-java/
     * @param matrix
     * @return
     */
    public ArrayList<Integer> spiralOrder(int[][] matrix) {
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


    //TODO 边界过于复杂调试失败
    public List<Integer> spiralOrder1(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int circleCount;
        if (m < n) circleCount = m%2 == 0 ? m/2 : m/2 + 1;
        else circleCount = n%2 == 0 ? n/2 : n/2 + 1;
        List<Integer> result = new ArrayList<>();
        for (int k = 0; k < circleCount; k++){
            int i = 0, j = 0;
            while (j < n - k){
                if (j + k >= n || i + k >= n) break;
                result.add(matrix[i + k][j + k]);
                j++;
            }
            i++;
            while (i < m - k){
                if (i + k >= m || j + k >= n) break;
                result.add(matrix[i + k][j + k]);
                i++;
            }
            j--;
            while (j > 0 + k){
                if (j - k <= 0 || i - k <= 0) break;
                result.add(matrix[i - k][j - k]);
                j--;
            }
            i--;
            while (i > 0 + k ){
                if (i - k <= 0 || j - k <= 0) break;
                result.add(matrix[i - k][j - k]);
                i--;
            }
            j++;
        }
        return result;
    }

}
