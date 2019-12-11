
/**Given a binary tree, find the maximum path sum.
 For this problem, a path is defined as any sequence of nodes from
 some starting node to any node in the tree along the parent-child connections.
 The path does not need to go through the root.
 For example: Given the below binary tree,
   1
  / \
 2   3
 Return 6.
Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
Output: 42
 * Created by eugene on 16/2/13.
 */
class Solution {
public:
    /*这道求二叉树的最大路径和是一道蛮有难度的题，难就难在起始位置和结束位置可以为任意位置
    递归:递归计算左,右子树最大路径和,从左/右子树最大路径和与根节点中选出单侧最大值,
    再从单侧最大值,当前全路径和,全局最大路径和中选出最大值.
    TODO 注意节点值可能出现负值,比较时不能漏掉单节点情况.
        4
       / \
      11 13
     / \
    7   2
     */
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPath(root, maxSum);
        return maxSum;
    }
    int maxPath(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        int maxLeft = maxPath(node->left, maxSum);
        int maxRight = maxPath(node->right, maxSum);
        int maxSide = max({node->val, node->val+maxLeft, node->val+maxRight});//TODO 因为节点可能有负值,不能漏掉比较node->val
        maxSum = max({maxSum, maxSide, maxLeft+node->val+maxRight});//TODO 因为节点可能有负值,不能漏掉比较maxCurrent
        return maxSide;
    }
};
//public class BinaryTreeMaximumPathSum {
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//    /**
//     * http://www.programcreek.com/2013/02/leetcode-binary-tree-maximum-path-sum-java/
//     * 递归:递归计算左,右子树最大路径和,从左,右子树最大路径和与根节点中选出单侧最大值,
//     再从单侧最大值,当前全路径和,全局最大路径和中选出最大值.
//     * 注意节点值可能出现负值,比较时不能漏掉单节点情况.
//     */
//    private int maxSum = Integer.MIN_VALUE;
//    public int maxPathSum(TreeNode root) {
//        maxPath(root);
//        return maxSum;
//    }
//    private int maxPath(TreeNode root) {
//        if (root==null) return 0;
//        int maxLeft = maxPath(root.left);
//        int maxRight = maxPath(root.right);
//        //比较root.val, root.val+maxLeft, root.val+maxRight,TODO 因为节点可能有负值,不能漏掉比较root.val
//        int maxSide = Math.max(root.val, Math.max(root.val+maxLeft, root.val+maxRight));
//        //比较maxSum, maxCurrent, maxLeft+root.val+maxRight,TODO 因为节点可能有负值,不能漏掉比较maxCurrent
//        maxSum = Math.max(maxSum, Math.max(maxSide, maxLeft+root.val+maxRight));
//        return maxSide;
//    }
//
//}
