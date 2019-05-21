
/**Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 such that adding up all the values along the path equals the given sum.
 * Created by eugene on 16/1/31.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        if(root->val == sum && root->left == nullptr && root->right == nullptr) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

//public class PathSum {
//
//    //Definition for a binary tree node.
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//
//    //http://www.programcreek.com/2013/01/leetcode-path-sum/
//    public boolean hasPathSum(TreeNode root, int sum) {
//        if (root == null) return false;
//        if (root.val == sum && root.left == null && root.right == null) return true;
//        return hasPathSum(root.left, sum-root.val) || hasPathSum(root.right, sum-root.val);
//    }
//
//    /**
//     * 与Minimum Depth Of Binary Tree方法基本一致:类似层次遍历,使用队列,并额外使用一个队列存储深度.
//     * @param root
//     * @param sum
//     * @return
//     */
//    public boolean hasPathSum1(TreeNode root, int sum) {
//        if(root == null) return false;
//        LinkedList<TreeNode> nodes = new LinkedList<>();
//        LinkedList<Integer> values = new LinkedList<>();
//        nodes.add(root);
//        values.add(root.val);
//        while(!nodes.isEmpty()){
//            TreeNode node = nodes.poll();
//            int sumValue = values.poll();
//            if(node.left == null && node.right == null && sumValue==sum){
//                return true;
//            }
//            if(node.left != null){
//                nodes.add(node.left);
//                values.add(sumValue+node.left.val);
//            }
//            if(node.right != null){
//                nodes.add(node.right);
//                values.add(sumValue+node.right.val);
//            }
//        }
//        return false;
//    }
//
//}
