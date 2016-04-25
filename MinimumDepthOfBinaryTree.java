package leetcode111_120;

import java.util.*;

/**Given a binary tree, find its minimum depth.
 The minimum depth is the number of nodes along the shortest path from
 the root node down to the nearest leaf node.
 * Created by eugene on 16/1/30.
 */
public class MinimumDepthOfBinaryTree {

    //Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**
     * 类似Maximum Depth Of Binary Tree,注意边界条件不同.
     * @param root
     * @return
     */
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        return getMin(root);
    }
    private int getMin(TreeNode root){
        if (root == null) return Integer.MAX_VALUE; //TODO 不是返回0
        if (root.left == null && root.right == null) {  //TODO 新增条件
            return 1;
        }
        return Math.min(getMin(root.left), getMin(root.right)) + 1;
    }

    /**
     * 类似层次遍历,使用队列,并额外使用一个队列存储深度.
     * @param root
     * @return
     */
    public int minDepth1(TreeNode root) {
        if (root==null) return 0;
        Queue<TreeNode> nodes = new LinkedList<>();
        Queue<Integer> counts = new LinkedList<>();
        nodes.offer(root);
        counts.offer(1);
        while (!nodes.isEmpty()){
            TreeNode node = nodes.poll();
            int count = counts.poll();
            if (node.left!=null){
                nodes.offer(node.left);
                counts.offer(count+1);
            }
            if (node.right!=null){
                nodes.offer(node.right);
                counts.offer(count+1);
            }
            if (node.left==null && node.right==null){
                return count;
            }
        }
        return 0;
    }

}
