package leetcode101_110;

/**Given inorder and postorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree.
 * Created by eugene on 16/1/26.
 */
public class ConstructBinaryTreeFromInorderAndPostorderTraversal {

    //Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }


    /**
     * 递归:后序序列最后一个为根.中序序列的根的左侧序列为左子树,右侧序列为右子树.
     根据左右序列长度可以在后序序列中找到左右子树.
     * 示例:
     in-order:   4 2 5 (1) 6 7 3 8
     post-order: 4 5 2  6 7 8 3  (1)
     * @param inorder
     * @param postorder
     * @return
     */
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return rebuild(postorder, inorder, 0, postorder.length-1, 0, inorder.length-1);
    }
    private TreeNode rebuild(int[] postorder, int[] inorder, int postL, int postR, int inL, int inR){
        if (postL>postR || inL>inR) return null;
        TreeNode root = new TreeNode(postorder[postR]);
        int i = 0;
        for (; i<inorder.length; i++){
            if (inorder[i] == postorder[postR]) break;
        }
        int postLeftLen = i - inL;
        root.left = rebuild(postorder, inorder, postL, postL+postLeftLen-1, inL, i-1);
        root.right = rebuild(postorder, inorder, postL+postLeftLen, postR-1, i+1, inR);
        return root;
    }

}
