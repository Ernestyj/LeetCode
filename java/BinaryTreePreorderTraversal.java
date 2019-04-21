package leetcode141_150;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**Given a binary tree, return the preorder traversal of its nodes' values.
 For example: Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
 return [1,2,3].
 Note: Recursive solution is trivial, could you do it iteratively?
 * Created by eugene on 16/3/3.
 */
public class BinaryTreePreorderTraversal {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root==null) return result;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()){
            TreeNode node = stack.pop();
            result.add(node.val);
            if (node.right!=null) stack.push(node.right);
            if (node.left!=null) stack.push(node.left);
        }
        return result;
    }

}
