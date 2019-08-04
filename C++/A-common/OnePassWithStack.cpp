
/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 * find the area of largest rectangle in the histogram.
 * For example,
 Given height = [2,1,5,6,2,3],
 return 10.
 * Created by DCLab on 1/5/2016.
 */
class Solution {
public:
    //时间复杂度：O(n) 维护一个栈，栈内只存高度递增的条形索引。这个动态栈的特点是：栈内元素一定比当前i指向的元素小。
    // 另一个关键点是弹栈过程中面积的计算（高*宽）：h[t] * (stack.isEmpty() ? i : i - stack.peek() - 1)。
    int largestRectangleArea(vector<int> &height) {
        stack<int> stk;
        int res = 0, i = 0;
        height.push_back(0);    //末尾添加dummy元素0
        while (i < height.size()) {
            if (stk.empty() || height[stk.top()] < height[i]) { //维护高度递增条形索引栈
                stk.push(i++);
            } else {    //当前元素小于栈顶元素
                int t = stk.top(); stk.pop();
                res = max(res, height[t] * (stk.empty()? i : (i - stk.top() - 1)));
            }
        }
        return res;
    }
};

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
                int t = stk.top(); stk.pop();   //stk.top()为左边界位置，t为坑的位置, i为右边界的位置
                if (stk.empty()) continue;
                res += (min(height[i], height[stk.top()]) - height[t]) * (i - stk.top() - 1);
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

/**
 * Given a 2D binary matrix filled with 0's and 1's,
 * find the largest rectangle containing all ones and return its area.
 * Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
 * Created by DCLab on 1/6/2016.
 */
class Solution {
public:
    //此题是之前那道的 Largest Rectangle in Histogram 的扩展，这道题的二维矩阵每一层向上都可以看做一个直方图，输入矩阵有多少行，就可以形成多少个直方图，
    // 对每个直方图都调用 Largest Rectangle in Histogram 中的方法，就可以得到最大的矩形面积。时间复杂为O(n^2)
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(!matrix.size()) return 0;
        int res = 0;
        vector<int> height(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    int largestRectangleArea(vector<int> &height) {
        int res = 0, i = 0;
        stack<int> stk;
        height.push_back(0);    //末尾添加dummy元素0
        while (i < height.size()) {
            if (stk.empty() || height[stk.top()] < height[i]) { //维护高度递增条形索引栈
                stk.push(i++);
            } else {    //当前元素小于栈顶元素
                int cur = stk.top(); stk.pop();
                res = max(res, height[cur] * (stk.empty() ? i : (i - stk.top() - 1)));
            }
        }
        return res;
    }
};

/**
 * Given a string containing just the characters '(' and ')', find the length of
 the longest valid (well-formed) parentheses substring.
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 Another example is ")()())", where the longest valid parentheses substring is "()()",
 which has length = 4.
 * Created by Eugene on 11/16/2015.
 */
class Solution {
public:
    // 定义个start变量来记录合法括号串的起始位置，我们遍历字符串，1. 如果遇到左括号，则将当前下标压入栈，
    // 2. 如果遇到右括号，2.1如果当前栈为空，则将下一个坐标位置记录到start，
    // 2.2 如果栈不为空，则将栈顶元素取出，此时若栈为空，则更新为结果和i - start + 1中的较大值，否则更新为结果和i - 栈顶元素中的较大值
    int longestValidParentheses(string s) {
        int maxLen = 0, start = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                if (stk.empty()) start = i + 1;
                else {
                    stk.pop();
                    maxLen = stk.empty() ? max(maxLen, i - start + 1) : max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }
};

