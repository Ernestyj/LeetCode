package leetcode41_50;

/**
 * Given n non-negative integers representing an elevation map where the width of
 * each bar is 1, compute how much water it is able to trap after raining.
 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 Ref: https://leetcode.com/problems/trapping-rain-water/
 * Created by DCLab on 11/25/2015.
 */
public class TrappingRainWater {

    public static void main(String[] args) {
        int[] height = {0,1,0,2,1,0,1,3,2,1,2,1};
        System.out.println("*****RESULT*****");
        int trapped = new TrappingRainWater().trap(height);
        System.out.println(trapped);
    }


    /** http://blog.unieagle.net/2012/10/31/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Atrapping-rain-water/
     * 思路：对某个值A[i]来说，能trapped的最多的water取决于在i之前最高的值leftMostHeight[i]
     和在i右边的最高的值rightMostHeight[i]（均不包含自身）。
     如果min(left,right) > A[i]，那么在i这个位置上能trapped的water就是min(left,right) – A[i]。
     * 第一遍从左到右计算数组leftMostHeight，第二遍从右到左计算rightMostHeight，
     在第二遍的同时就可以计算出i位置的结果了，而且并不需要开空间来存放rightMostHeight数组。
     * 时间复杂度是O(n)，只扫了两遍。
     * @param height
     * @return
     */
    public int trap(int[] height) {
        if (height == null || height.length <= 2) return 0;
        int[] leftMostHeight = new int[height.length];
        int len = height.length;
        int max = height[0];
        int trapped = 0;
        for (int i = 0; i < len; i++){    //left -> right
            leftMostHeight[i] = max;
            if (height[i] > max) max = height[i];
        }
        max = height[len - 1];
        for (int i = len - 1; i >= 0; i--){    //right -> left
            if (Math.min(leftMostHeight[i], max) > height[i]){
                trapped += Math.min(leftMostHeight[i], max) - height[i];
            }
            if (height[i] > max) max = height[i];
        }
        return trapped;
    }

}
