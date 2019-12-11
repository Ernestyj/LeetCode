
/**Given inorder and postorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree.
 * Created by eugene on 16/1/26.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return rebuild(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    TreeNode* rebuild(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int postL, int postR){
        if(inL>inR || postL>postR) return nullptr;
        int i = 0;
        for (; i < inorder.size(); ++i) {
            if(inorder[i]==postorder[postR]) break; //不是取postorder.back()
        }
        int postLeftLen = i-inL;
        TreeNode* node = new TreeNode(postorder[postR]);
        node->left = rebuild(inorder, postorder, inL, i-1, postL, postL+postLeftLen-1);
        node->right = rebuild(inorder, postorder, i+1, inR, postL+postLeftLen, postR-1);//不是postR而是postR-1，小心处理
        return node;
    }
};
//public class ConstructBinaryTreeFromInorderAndPostorderTraversal {
//    //Definition for a binary tree node.
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//    /**
//     * 递归:后序序列最后一个为根.中序序列的根的左侧序列为左子树,右侧序列为右子树.
//     根据左右序列长度可以在后序序列中找到左右子树.
//     * 示例:
//     in-order:   4 2 5 (1) 6 7 3 8
//     post-order: 4 5 2  6 7 8 3  (1)
//     */
//    public TreeNode buildTree(int[] inorder, int[] postorder) {
//        return rebuild(postorder, inorder, 0, postorder.length-1, 0, inorder.length-1);
//    }
//    private TreeNode rebuild(int[] postorder, int[] inorder, int postL, int postR, int inL, int inR){
//        if (postL>postR || inL>inR) return null;
//        TreeNode root = new TreeNode(postorder[postR]);
//        int i = 0;
//        for (; i<inorder.length; i++){
//            if (inorder[i] == postorder[postR]) break;
//        }
//        int postLeftLen = i - inL;
//        root.left = rebuild(postorder, inorder, postL, postL+postLeftLen-1, inL, i-1);
//        root.right = rebuild(postorder, inorder, postL+postLeftLen, postR-1, i+1, inR);
//        return root;
//    }
//
//}
