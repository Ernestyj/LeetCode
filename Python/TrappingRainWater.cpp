
/**
 * Given n non-negative integers representing an elevation map where the width of
 * each bar is 1, compute how much water it is able to trap after raining.
 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 Ref: https://leetcode.com/problems/trapping-rain-water/
 * Created by DCLab on 11/25/2015.
 */
class Solution {
public:
    //遍历高度，1. 如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈(注意我们不直接把高度压入栈，而是把坐标压入栈，这样方便我们在后来算水平距离)。
    // 2. 当遇到比栈顶高度大的时候，就说明有可能会有坑存在，可以装雨水。此时我们栈里至少有一个高度，2.1如果只有一个的话，那么不能形成坑，我们直接跳过，
    // 2.2 如果多余一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量
    int trap(vector<int>& height) {
        stack<int> stk;
        int i = 0, res = 0;
        while (i < height.size()) {
            if (stk.empty() || height[i] <= height[stk.top()]) {
                stk.push(i++);
            } else {
                int pit = stk.top(); stk.pop();   //pit为坑的位置, stk.top()为左边界位置，i为右边界的位置
                if (stk.empty()) continue;
                int l = stk.top(), r = i;
                res += (min(height[r], height[l]) - height[pit]) * (r - l - 1);
            }
        }
        return res;
    }

    //left和right两个指针分别指向数组的首尾位置，从两边向中间扫描，在当前两指针确定的范围内，先比较两头找出较小值，
    // 如果较小值是left指向的值，则从左向右扫描，如果较小值是right指向的值，则从右向左扫描，
    // 若遇到的值比当较小值小，则将差值存入结果；如遇到的值大，则重新确定新的窗口范围。以此类推直至left和right指针重合
    int trap(vector<int>& height) { //遍历一遍解法 TODO 太难理解
        int l = 0, r = height.size() - 1, maxH = 0, res = 0;
        while (l < r) {
            int lower = height[(height[l] < height[r]) ? l++ : r--];
            maxH = max(maxH, lower);
            res += maxH - lower;
        }
        return res;
    }
};
//public class TrappingRainWater {
//
//    //https://leetcode.com/discuss/16171/sharing-my-simple-c-code-o-n-time-o-1-space
//    //双指针,只扫描一遍,O(n),空间O(1) TODO 较难理解
//    public int trap(int[] heights) {
//        if ( heights.length <= 2 ) { return 0; }
//        int l = 0, r = heights.length-1;
//        int totalArea = 0;
//        int leftMaxH = heights[l], rightMaxH = heights[r];
//        while (l<r) {
//            if ( heights[l]<heights[r] ) {
//                leftMaxH = Math.max(leftMaxH, heights[++l]);
//                totalArea += leftMaxH-heights[l];
//            } else {
//                rightMaxH = Math.max(rightMaxH, heights[--r]);
//                totalArea += rightMaxH-heights[r];
//            }
//        }
//        return totalArea;
//    }
//
//    /** TODO 此法容易理解
//     * http://blog.unieagle.net/2012/10/31/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Atrapping-rain-water/
//     * 思路：对某个值A[i]来说，能trapped的最多的water取决于在i之前最高的值leftMostHeight[i]
//     和在i右边的最高的值rightMostHeight[i]（均不包含自身）。
//     如果min(left,right) > A[i]，那么在i这个位置上能trapped的water就是min(left,right) – A[i]。
//     * 第一遍从左到右计算数组leftMostHeight，第二遍从右到左计算rightMostHeight，
//     在第二遍的同时就可以计算出i位置的结果了，而且并不需要开空间来存放rightMostHeight数组。
//     * 时间复杂度是O(n)，只扫了两遍。空间O(n).
//     * @param height
//     * @return
//     */
//    public int trap1(int[] height) {
//        if (height == null || height.length <= 2) return 0;
//        int[] lMax = new int[height.length];
//        int len = height.length;
//        int max = height[0];
//        int trapped = 0;
//        for (int i = 0; i<len; i++){    //left -> right
//            lMax[i] = max;
//            if (height[i]>max) max = height[i];
//        }
//        max = height[len-1];
//        for (int i = len-1; i>=0; i--){    //right -> left
//            if (Math.min(lMax[i], max) > height[i]){
//                trapped += Math.min(lMax[i], max) - height[i];
//            }
//            if (height[i]>max) max = height[i];
//        }
//        return trapped;
//    }
//
//}
