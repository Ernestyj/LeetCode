package leetcode231_240;

import java.util.LinkedList;

/**Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between
 two nodes v and w as the lowest node in T that has both v and w as descendants
 (where we allow a node to be a descendant of itself).”
 * Created by eugene on 16/4/30.
 */
public class LowestCommonAncestorOfBinaryTree {

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }


    /**
     * 若当前子树同时含p和q,根节点为LCA;若只有其一,则LCA为其一;若都不含,则为null.
     https://leetcode.com/discuss/45386/4-lines-c-java-python-ruby
     * @param root
     * @param p
     * @param q
     * @return
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if(left != null && right != null) return root;
        else if(left==null) return right;
        else return left;
    }

    //TODO 错误
    public TreeNode lowestCommonAncestor1(TreeNode root, TreeNode p, TreeNode q) {
        if (root==null) return null;
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()){
            TreeNode node = queue.poll();
            int val = node.val;
            if (val==p.val || val==q.val) return node;
            if (node.left!=null) {
                if (node.left.val==p.val || node.left.val==q.val) return node;
                else queue.offer(node.left);
            }
            if (node.right!=null) {
                if (node.right.val==q.val || node.right.val==p.val) return node;
                else queue.offer(node.right);
            }
        }
        return null;
    }

}
