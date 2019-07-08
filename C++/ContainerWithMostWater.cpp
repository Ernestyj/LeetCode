
/**Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 Note: You may not slant the container.
 * Created by eugene on 16/6/1.
 */
class Solution {
public:
    int maxArea(vector<int>& height) {//类似Trapping Rain Water的双指针解法
        int maxArea = 0, l = 0, r = height.size()-1;
        while (l<r){
            maxArea = max(maxArea, min(height[l], height[r]) * (r-l));
            if(height[l]<height[r]) ++l;//核心方法:Every time move the smaller value pointer to inner array
            else --r;
        }
        return maxArea;
    }
};
//public class ContainerWithMostWater {
//
//    //规律证明参见:https://leetcode.com/discuss/59635/easy-concise-java-o-n-solution-with-proof-and-explanation
//    //类似Trapping Rain Water的双指针解法
//    public int maxArea(int[] height) {
//        if (height==null || height.length<=1) return 0;
//        int l = 0, r = height.length-1;
//        int maxArea = 0;
//        while (l<r){
//            maxArea = Math.max(maxArea, Math.min(height[l], height[r])*(r-l));
//            //核心方法:Every time move the smaller value pointer to inner array
//            if (height[l]<height[r]) l++;
//            else r--;
//        }
//        return maxArea;
//    }
//
//    //brute force, 超时
//    public int maxArea1(int[] height) {
//        if (height==null || height.length<=1) return 0;
//        int len = height.length;
//        int maxArea = 0;
//        for (int i=0; i<len; i++){
//            for (int j=i+1; j<len; j++){
//                int area = Math.min(height[i], height[j])*(j-i);
//                maxArea = Math.max(maxArea, area);
//            }
//        }
//        return maxArea;
//    }
//
//}
