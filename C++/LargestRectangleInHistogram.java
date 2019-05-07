package leetcode81_90;

import java.util.Arrays;
import java.util.Stack;

/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 * find the area of largest rectangle in the histogram.
 * For example,
 Given height = [2,1,5,6,2,3],
 return 10.
 * Created by DCLab on 1/5/2016.
 */
public class LargestRectangleInHistogram {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }


    /**
     * 参考：http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
     * 方法1：维护一个栈，栈内只存高度递增的条形索引。这个动态栈的特点是：栈内元素一定比当前i指向的元素小。
     * 另一个关键点是弹栈过程中面积的计算（高*宽）：h[t] * (stack.isEmpty() ? i : i - stack.peek() - 1)。
     * 时间复杂度：O(n)。
     * 方法2：从左往右扫描，对合适的右边界（此条形大于其右边条形），再往左遍历面积。时间复杂度：O(n*n)。
     * @param height
     * @return
     */
    public int largestRectangleArea(int[] height) {
        if (height == null || height.length == 0) return 0;
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        int i = 0;
        int[] h = Arrays.copyOf(height, height.length + 1); //末尾添加dummy元素0
        while(i < h.length){
            if(stack.isEmpty() || h[stack.peek()] <= h[i]){ //维护高度递增条形索引栈
                stack.push(i++);
            }else { //当前元素小于栈顶元素
                int p = stack.pop();
                //高h[p]，宽stack.isEmpty() ? i : i - stack.peek() - 1
                maxArea = Math.max(maxArea, h[p] * (stack.isEmpty() ? i : i - stack.peek() - 1));
            }
        }
        return maxArea;
    }

}
