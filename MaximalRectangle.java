package leetcode81_90;

import java.util.Stack;

/**
 * Given a 2D binary matrix filled with 0's and 1's,
 * find the largest rectangle containing all ones and return its area.
 * Created by DCLab on 1/6/2016.
 */
public class MaximalRectangle {

    /**DP方法也行,但相对复杂难以理解
     * https://leetcode.com/discuss/52670/solution-based-maximum-rectangle-histogram-with-explanation
     * 高效的方法：转化为Largest Rectangle in Histogram的问题，时间复杂为O(n^2).
     * @param matrix
     * @return
     */
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length==0) return 0;
        int m = matrix.length;
        int n = matrix[0].length;
        //实际上height可以分配一维数组存储
        int[][] height = new int[m][n+1]; //末尾多加一个dummy元素0
        int maxArea = 0;
        //矩阵按行转化为柱状图
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == '0') {
                    height[i][j] = 0;
                } else {
                    height[i][j] = (i==0)? 1 : height[i-1][j]+1;
                }
            }
        }
        //计算每行柱状图的最大矩形面积
        for (int i=0; i<m; i++) {
            int area = maxAreaInHist(height[i]);
            if (area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
    //O(n) Largest Rectangle in Histogram算法，传入的height数组最后一个元素是多加的dummy元素
    private int maxAreaInHist(int[] height) {
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        int maxArea = 0;
        while (i < height.length) {
            if (stack.isEmpty() || height[stack.peek()] <= height[i]) {
                stack.push(i++);
            } else {
                int t = stack.pop();
                maxArea = Math.max(maxArea, height[t] * (stack.isEmpty() ? i : i - stack.peek() - 1));
            }
        }
        return maxArea;
    }

}
