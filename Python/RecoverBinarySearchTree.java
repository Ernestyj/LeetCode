package leetcode91_100;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 Recover the tree without changing its structure.
 Note: A solution using O(n) space is pretty straight forward.
 Could you devise a constant space solution?
 * Created by eugene on 16/1/19.
 */
public class RecoverBinarySearchTree {

    //Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }


    /**
     * 空间复杂度O(1),注意pre存的是中序次序的上一个节点
     * 示例:The inorder traversal is :  1 3 4 6 7 8 10 13 14
     * If we change the value 4 and 8:  1 3 (8) 6 7 (4) 10 13 14
     * 参考:http://yucoding.blogspot.com/2013/03/leetcode-question-75-recover-binary.html
     */
    private TreeNode first=null, second=null, pre=null;
    public void recoverTree(TreeNode root) {
        inOrder(root);
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
    private void inOrder(TreeNode root){
        if (root == null) return;
        inOrder(root.left);
        if (pre == null) pre = root;
        else {
            if (pre.val > root.val){
                if (first == null) first = pre; //第一个错误节点:当前节点的上一节点
                second = root;//第二个错误节点:当前节点
            }
            pre = root;
        }
        inOrder(root.right);
    }


    /**
     * 空间复杂度O(n)
     * @param root
     */
    public void recoverTree1(TreeNode root) {
        List<Integer> ints = new ArrayList<>();
        List<TreeNode> nodes = new ArrayList<>();
        inOrderTraverse(root, ints, nodes);
        Collections.sort(ints);
        for (int i=0; i<ints.size(); i++){
            nodes.get(i).val = ints.get(i);
        }
    }
    private void inOrderTraverse(TreeNode root, List<Integer> ints, List<TreeNode> nodes){
        if (root==null) return;
        inOrderTraverse(root.left, ints, nodes);
        ints.add(root.val);
        nodes.add(root);
        inOrderTraverse(root.right, ints, nodes);
    }

}
