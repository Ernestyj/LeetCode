package leetcode101_110;

/**Given preorder and inorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree.
 * Created by eugene on 16/1/25.
 */
public class ConstructBinaryTreeFromPreorderAndInorderTraversal {

    //Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }


    /**http://www.programcreek.com/2014/06/leetcode-construct-binary-tree-from-preorder-and-inorder-traversal-java/
     * 递归:先序序列第一个为根.中序序列的根的左侧序列为左子树,右侧序列为右子树.
     根据左右序列长度可以在先序序列中找到左右子树.
     * 示例:
     in-order:   4 2 5 (1) 6 7 3 8
     pre-order: (1) 2 4 5  3 7 6 8
     * @param preorder
     * @param inorder
     * @return
     */
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return rebuild(preorder, inorder, 0, preorder.length-1, 0, inorder.length-1);
    }
    private TreeNode rebuild(int[] preorder, int[] inorder, int preL, int preR, int inL, int inR){
        if (preL>preR || inL>inR) return null;
        TreeNode root = new TreeNode(preorder[preL]);
        int i = 0;
        for (; i<inorder.length; i++){
            if (inorder[i] == preorder[preL]) break;
        }
        int preLeftLen = i - inL;
        root.left = rebuild(preorder, inorder, preL+1, preL+preLeftLen, inL, i-1);
        root.right = rebuild(preorder, inorder, preL+preLeftLen+1, preR, i+1, inR);
        return root;
    }

}
