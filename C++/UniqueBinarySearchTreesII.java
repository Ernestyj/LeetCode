package leetcode91_100;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Given n, generate all structurally unique BST's (binary search trees) that
 store values 1...n.
 * Created by eugene on 16/1/16.
 */
public class UniqueBinarySearchTreesII {

    //Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) {
            val = x;
        }
    }

    /**https://leetcode.com/discuss/10254/a-simple-recursive-solution
     * DP与回溯:在循环中进行递归,类似NQueens.
     * I start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n.
     So if I pick i-th node as my root, the left subtree will contain elements 1 to (i-1),
     and the right subtree will contain elements (i+1) to n. I use recursive calls to get back all
     possible trees for left and right subtrees and combine them in all possible ways with the root.
     * @param n
     * @return
     */
    public List<TreeNode> generateTrees(int n) {
        if (n==0) return new ArrayList<>();
        return genTrees(1, n);
    }
    private List<TreeNode> genTrees(int start, int end) {
        List<TreeNode> list = new ArrayList<>();
        if(start>end) {
            list.add(null);
            return list;
        } else if(start==end){
            list.add(new TreeNode(start));
            return list;
        }
        for(int i=start;i<=end;i++) {
            List<TreeNode> left = genTrees(start, i-1);
            List<TreeNode> right = genTrees(i+1, end);
            for(TreeNode l: left) {
                for(TreeNode r: right) {
                    TreeNode root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    list.add(root);
                }
            }
        }
        return list;
    }

}
