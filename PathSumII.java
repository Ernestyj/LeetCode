package leetcode111_120;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**Given a binary tree and a sum, find all root-to-leaf paths where each path's sum
 equals the given sum.
 * Created by eugene on 16/2/1.
 */
public class PathSumII {

    //Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    //dfs,递归,与Path Sum思路一致,但引入一个数组存储结果
    //http://www.programcreek.com/2014/05/leetcode-path-sum-ii-java/
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null) return result;
        List<Integer> path = new ArrayList<>();
        path.add(root.val);
        pathSum(result, path, root, sum-root.val);  //sum-root.val而非sum
        return result;
    }
    private void pathSum(List<List<Integer>> result, List<Integer> path, TreeNode root, int sum){
        //if (root == null) return; //冗余
        if (root.left==null && root.right==null && sum==0){ //这里sum判0而不是sum==root.val
            result.add(new ArrayList<>(path));
        }
        if (root.left!=null) {  //有点回溯的感觉
            path.add(root.left.val);
            pathSum(result, path, root.left, sum-root.left.val);    //sum-root.left.val而非sum-root.val
            path.remove(path.size()-1);
        }
        if (root.right!=null) {
            path.add(root.right.val);
            pathSum(result, path, root.right, sum-root.right.val);  //sum-root.right.val而非sum-root.val
            path.remove(path.size()-1);
        }
    }

    //层次遍历,超时
    public List<List<Integer>> pathSum1(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null) return result;
        LinkedList<TreeNode> nodes = new LinkedList<>();
        LinkedList<Integer> sums = new LinkedList<>();
        LinkedList<Integer> path = new LinkedList<>();
        nodes.add(root);
        sums.add(root.val);
        path.add(root.val);
        while(!nodes.isEmpty()){
            TreeNode node = nodes.poll();
            int sumValue = sums.poll();
            if(node.left == null && node.right == null && sumValue==sum){
                result.add(new LinkedList<>(path));
            }
            if(node.left != null){
                nodes.add(node.left);
                sums.add(sumValue+node.left.val);
                path.add(node.left.val);
            }
            if(node.right != null){
                nodes.add(node.right);
                sums.add(sumValue+node.right.val);
                path.add(node.right.val);
            }
        }
        return result;
    }

}
