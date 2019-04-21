package leetcode221_230;

import java.util.ArrayList;

/**Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 Note: You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 Follow up:
 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 Hint:
 Try to utilize the property of a BST.
 What if you could modify the BST node's structure?
 The optimal runtime complexity is O(height of BST).
 * Created by eugene on 16/4/25.
 */
public class KthSmallestElementInBST {

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**https://leetcode.com/discuss/43771/implemented-java-binary-search-order-iterative-recursive
     * 二分搜索O(h=logn),充分利用BST的大小排列性质
     * @param root
     * @param k
     * @return
     */
    public int kthSmallest(TreeNode root, int k) {
        int count = countNodes(root.left);
        if (k <= count) {   //在左子树
            return kthSmallest(root.left, k);
        } else if (k > count + 1) { //在右子树
            return kthSmallest(root.right, k-1-count); // 1 is counted as current node
        } else return root.val;
    }
    private int countNodes(TreeNode n) {
        if (n == null) return 0;
        return 1 + countNodes(n.left) + countNodes(n.right);
    }


    //递归中序遍历取第k小 O(n)
    ArrayList<Integer> list = new ArrayList<>();
    public int kthSmallest1(TreeNode root, int k) {
        inorder(root);
        return list.get(k-1);
    }
    private void inorder(TreeNode node){
        if (node==null) return;
        inorder(node.left);
        list.add(node.val);
        inorder(node.right);
    }

}
