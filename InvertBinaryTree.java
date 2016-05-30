package leetcode221_230;

/**https://leetcode.com/problems/invert-binary-tree/
 * Invert a binary tree.
     4
   /   \
  2     7
  / \   / \
 1   3 6   9
 to
     4
   /   \
  7     2
  / \   / \
 9   6 3   1
 * Created by eugene on 16/4/21.
 */
public class InvertBinaryTree {

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public TreeNode invertTree(TreeNode root) {
        invertHelper(root);
        return root;
    }
    private void invertHelper(TreeNode root){
        if (root==null) return;
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        invertHelper(root.left);
        invertHelper(root.right);
    }

}
