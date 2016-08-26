package leetcode101_110;

import java.util.*;

/**Given a binary tree, return the bottom-up level order traversal of its nodes' values.
 (ie, from left to right, level by level from leaf to root).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 return its level order traversal as: [ [15,7], [9,20], [3] ]
 * Created by eugene on 16/1/27.
 */
public class BinaryTreeLevelOrderTraversalII {

    //Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }


    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if(root==null) return result;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(q.size()>0){
            List<Integer> list = new ArrayList<>();
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode node = q.poll();
                list.add(node.val);
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
            }
            result.add(0,list);
        }
        return result;
    }

}
