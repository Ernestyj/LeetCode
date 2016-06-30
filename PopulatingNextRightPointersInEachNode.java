package leetcode111_120;

import java.util.LinkedList;
import java.util.Queue;

/**Populate each next pointer to point to its next right node.
 If there is no next right node, the next pointer should be set to NULL.
 Initially, all next pointers are set to NULL.
 Note: You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 * Created by eugene on 16/2/5.
 */
public class PopulatingNextRightPointersInEachNode {

    public static class TreeLinkNode {
        int val;
        TreeLinkNode left, right, next;
        TreeLinkNode(int x) { val = x; }
    }

    //https://leetcode.com/discuss/67291/java-solution-with-constant-space
    //PopulatingNextRightPointersInEachNodeII 通用解法
    public void connect(TreeLinkNode root) {
        TreeLinkNode levelHead = new TreeLinkNode(0);
        TreeLinkNode pre = levelHead, cur = root;
        while (cur != null) {
            if (cur.left != null) {
                pre.next = cur.left;
                pre = pre.next;
            }
            if (cur.right != null) {
                pre.next = cur.right;
                pre = pre.next;
            }
            cur = cur.next;
            if (cur == null) {
                pre = levelHead;
                cur = levelHead.next;
                levelHead.next = null;
            }
        }
    }

    //https://leetcode.com/discuss/19061/java-solution-with-o-1-memory-o-n-time
    public void connect1(TreeLinkNode root) {
        TreeLinkNode levelHead = root;
        while(levelHead!=null){
            TreeLinkNode cur = levelHead;
            while(cur!=null){
                if(cur.left!=null) cur.left.next = cur.right;
                if(cur.right!=null && cur.next!=null) cur.right.next = cur.next.left;
                cur = cur.next;
            }
            levelHead = levelHead.left;
        }
    }

    /**
     * 由于题目中的二叉树是完全二叉树,找到规律可用递归求解(OJ 82%);
     1. 根节点的左子树，其next是该根节点的右子树;
     2. 根节点的右子树，其next是该根节点next节点的左子树.
     空间复杂度O(1)
     * https://gist.github.com/benjaminwu7/4700435
     * @param root
     */
    public void connect2(TreeLinkNode root) {
        if(root == null) return;
        TreeLinkNode leftN = root.left;
        TreeLinkNode rightN = root.right;
        while(leftN != null){   //链接兄弟节点,及这对兄弟节点下所有相邻的堂兄弟节点对
            leftN.next = rightN;
            leftN = leftN.right;
            rightN = rightN.left;
        }
        connect(root.left);
        connect(root.right);
    }

}
