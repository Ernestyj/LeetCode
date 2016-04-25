package leetcode101_110;

import java.util.*;

/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 For example: Given binary tree {3,9,20,#,#,15,7},
 return its zigzag level order traversal as: [ [3], [20,9], [15,7] ]
 * Created by eugene on 16/1/23.
 */
public class BinaryTreeZigzagLevelOrderTraversal {

    //Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        boolean needReverse = false;
        if (root==null) return result;
        Stack<TreeNode> curStack = new Stack<>();
        Stack<TreeNode> nextStack = new Stack<>();
        curStack.push(root);
        while (!curStack.isEmpty()){
            TreeNode node = curStack.pop();
            temp.add(node.val);
            if (needReverse) {
                if (node.right!=null) nextStack.push(node.right);
                if (node.left!=null) nextStack.push(node.left);
            } else {
                if (node.left!=null) nextStack.push(node.left);
                if (node.right!=null) nextStack.push(node.right);
            }
            if (curStack.isEmpty()) {
                result.add(temp);
                temp = new ArrayList<>();
                needReverse = !needReverse;
                curStack = nextStack;
                nextStack = new Stack<>();
            }
        }
        return result;
    }

}
