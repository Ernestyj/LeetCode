
/**Given a binary tree, flatten it to a linked list in-place.
 * Created by eugene on 16/2/2.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
private:
    TreeNode* pre = nullptr;
};
//public class FlattenBinaryTreeToLinkedList {
//    //Definition for a binary tree node.
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//
//    private TreeNode prev = null;
//    /**
//     * https://leetcode.com/discuss/30719/my-short-post-order-traversal-java-solution-for-share
//     */
//    public void flatten(TreeNode root) {
//        if (root == null) return;
//        flatten(root.right);
//        flatten(root.left);
//        root.right = prev;
//        root.left = null;
//        prev = root;
//    }
//
//    /**
//     * dfs,先序
//     * @param root
//     */
//    public void flatten1(TreeNode root) {
//        List<TreeNode> preOrderList = new ArrayList<>();
//        preOrderTraversal(preOrderList, root);
//        for (int i=0; i<preOrderList.size()-1; i++){
//            TreeNode node = preOrderList.get(i);
//            node.left = null;
//            node.right = preOrderList.get(i+1);
//        }
//    }
//    private void preOrderTraversal(List<TreeNode> preOrderList, TreeNode root){
//        if (root==null) return;
//        preOrderList.add(root);
//        preOrderTraversal(preOrderList, root.left);
//        preOrderTraversal(preOrderList, root.right);
//    }
//
//}
