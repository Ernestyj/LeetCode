package leetcode101_110;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 return its level order traversal as: [ [3], [9,20], [15,7] ]
 * Created by eugene on 16/1/22.
 */
public class BinaryTreeLevelOrderTraversal {

    //Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**
     * 广度优先搜索，使用队列实现。
     */
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if(root == null) return res;
        LinkedList<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int n = q.size();
            List<Integer> list = new LinkedList<>();
            for(int i=0; i<n; i++) {
                TreeNode node = q.poll();
                if(node.left != null) q.offer(node.left);
                if(node.right != null) q.offer(node.right);
                list.add(node.val);
            }
            res.add(list);
        }
        return res;
    }

}
