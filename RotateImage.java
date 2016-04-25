package leetcode41_50;

/**
 * You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).
 Follow up:
 Could you do this in-place?
 * Created by DCLab on 12/1/2015.
 */
public class RotateImage {

    public static void main(String[] args) {
        int[][] matrix = {{1,2},{3,4}};
        int len = matrix.length;
        System.out.println("*****RESULT*****");
        new RotateImage().rotate(matrix);
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

    }


    //先转置再列逆转
    public void rotate(int[][] matrix) {
        int len = matrix.length;
        for (int i = 0; i < len; i++){
            for (int j = i + 1; j < len; j++){
                reverseSwap(matrix, i, j);
            }
        }
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len / 2; j++){
                colSwap(matrix, i, j, len);
            }
        }
    }
    private void reverseSwap(int[][] matrix, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
    private void colSwap(int[][] matrix, int i, int j, int len) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[i][len - j - 1];
        matrix[i][len - j - 1] = temp;
    }
}
