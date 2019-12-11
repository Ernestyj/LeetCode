
/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 Assume a BST is defined as follows:
 1 The left subtree of a node contains only nodes with keys less than the node's key.
 2 The right subtree of a node contains only nodes with keys greater than the node's key.
 3 Both the left and right subtrees must also be binary search trees.
 * Created by eugene on 16/1/18.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
    bool dfs(TreeNode* root, long long min, long long max){
        if(!root) return true;
        if(min>=root->val ||root->val>=max) return false;
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
};
//public class ValidateBinarySearchTree {
//
//    //Definition for a binary tree node.
//    public class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) {
//            val = x;
//        }
//    }
//    /**
//     * http://www.programcreek.com/2012/12/leetcode-validate-binary-search-tree-java/
//     * @param root
//     * @return
//     */
//    public boolean isValidBST(TreeNode root) {
//        return dfs(root, Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY);
//    }
//    private boolean dfs(TreeNode root, double min, double max){
//        if (root == null) return true;
//        if (min>=root.val || root.val>=max) return false;
//        return dfs(root.left, min, root.val) && dfs(root.right, root.val, max);
//    }
//
//
//    private boolean isValid = true;
//    private TreeNode pre = null;
//    /**与上述方法时间复杂度一致
//     * 另一种递归思路,类似Recover Binary Search Tree
//     * 注意pre存的是中序次序的上一个节点
//     * @param root
//     * @return
//     */
//    public boolean isValidBST1(TreeNode root) {
//        inOrder(root);
//        return isValid;
//    }
//    private void inOrder(TreeNode root){
//        if (root == null) return;
//        inOrder(root.left);
//        if (pre == null) pre = root;
//        else {
//            if (pre.val >= root.val){
//                isValid = false;
//                return;
//            }
//            pre = root;
//        }
//        inOrder(root.right);
//    }
//
//}
