package leetcode51_60;

import java.util.List;

/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 For example,
 Given n = 3,
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 * Created by Eugene on 12/12/2015.
 */
public class SpiralMatrixII {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        int[][] matrix = new SpiralMatrixII().generateMatrix(5);
        for (int[] i : matrix){
            for (int j : i){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }


    //若只剩下一行/列，则只处理此行/列，其余按circle方式处理
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        if (n == 0) return matrix;
        if (n == 1) {
            matrix[0][0] = 1;
            return matrix;
        }
        int x = 0, y = 0, k = 1, i = 0;
        while(n > 0){
            if(n==1){//if one row/column left, no circle can be formed
                matrix[x++][y] = k++;
                break;
            }
            //below, process a circle
            for(i=0;i<n-1;i++) matrix[x][y++] = k++;//top - move right
            for(i=0;i<n-1;i++) matrix[x++][y] = k++;//right - move down
            for(i=0;i<n-1;i++) matrix[x][y--] = k++;//bottom - move left
            for(i=0;i<n-1;i++) matrix[x--][y] = k++;//left - move up
            x++;
            y++;
            n=n-2;
        }
        return matrix;
    }

}
