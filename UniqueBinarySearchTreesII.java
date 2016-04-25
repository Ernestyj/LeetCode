package leetcode91_100;

import java.util.LinkedList;
import java.util.List;

/**
 * Given n, generate all structurally unique BST's (binary search trees) that
 store values 1...n.
 * Created by eugene on 16/1/16.
 */
public class UniqueBinarySearchTreesII {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }


    //Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) {
            val = x;
        }
    }


    /**http://www.programcreek.com/2014/05/leetcode-unique-binary-search-trees-ii-java/
     * DP与回溯:在循环中进行递归,类似NQueens. TODO 重温
     * @param n
     * @return
     */
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) return new LinkedList<>();
        return generateTrees(1, n);
    }
    private List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> list = new LinkedList<>();
        if (start > end) {  //空节点
            list.add(null);
            return list;
        }
        for (int i = start; i <= end; i++) {
            List<TreeNode> lefts = generateTrees(start, i - 1);
            List<TreeNode> rights = generateTrees(i + 1, end);
            for (TreeNode left : lefts) {
                for (TreeNode right : rights) {
                    TreeNode node = new TreeNode(i);
                    node.left = left;
                    node.right = right;
                    list.add(node);
                }
            }
        }
        return list;
    }

}
