

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
    void helper(TreeNode* node){
        if(node == nullptr) return;
        //swap(node->left, node->right);//这句也可以放这里
        helper(node->left);
        helper(node->right);
        swap(node->left, node->right);
    }
};
//public class InvertBinaryTree {
//
//    class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//
//    public TreeNode invertTree(TreeNode root) {
//        invertHelper(root);
//        return root;
//    }
//    private void invertHelper(TreeNode root){
//        if (root==null) return;
//        TreeNode temp = root.left;
//        root.left = root.right;
//        root.right = temp;
//        invertHelper(root.left);
//        invertHelper(root.right);
//    }
//
//}
