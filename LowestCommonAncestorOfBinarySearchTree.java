package leetcode231_240;

/**Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
 between two nodes v and w as the lowest node in T that has both v and w as descendants
 (where we allow a node to be a descendant of itself).”
 * Created by eugene on 16/4/29.
 */
public class LowestCommonAncestorOfBinarySearchTree {

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    //简洁版
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while ((root.val - p.val) * (root.val - q.val) > 0)
            root = p.val < root.val ? root.left : root.right;
        return root;
    }

    static TreeNode node;
    public TreeNode lowestCommonAncestor1(TreeNode root, TreeNode p, TreeNode q) {
        binarySearch(root, p, q);
        return node;
    }
    private void binarySearch(TreeNode root, TreeNode p, TreeNode q){
        if (root==null) return;
        int min = p.val, max = q.val;
        if (p.val>q.val) {
            min = q.val;
            max = p.val;
        }
        if (max<root.val) binarySearch(root.left, p ,q);
        else if (root.val<min) binarySearch(root.right, p, q);
        else node = root;
    }

}
