package leetcode221_230;

import java.util.LinkedList;

/**Given a complete binary tree, count the number of nodes.
 * Created by eugene on 16/4/16.
 */
public class CountCompleteTreeNodes {

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**
     * http://www.programcreek.com/2014/06/leetcode-count-complete-tree-nodes-java/
     * 满二叉树节点数=2^h-1
     * @param root
     * @return
     */
    public int countNodes(TreeNode root) {
        int leftDepth = leftDepth(root);
        int rightDepth = rightDepth(root);
        if (leftDepth == rightDepth) return (1<<leftDepth)-1;
        else return 1+countNodes(root.left)+countNodes(root.right);
    }
    private int rightDepth(TreeNode root) {
        int h = 0;
        while (root!=null) {
            root = root.right;
            h++;
        }
        return h;
    }
    private int leftDepth(TreeNode root) {
        int h = 0;
        while (root!=null) {
            root = root.left;
            h++;
        }
        return h;
    }

    //超时
    public int countNodes1(TreeNode root) {
        if (root==null) return 0;
        LinkedList<TreeNode> q = new LinkedList<>();
        LinkedList<TreeNode> qNext = new LinkedList<>();
        int count = 1;
        q.offer(root);
        while (!q.isEmpty()){
            TreeNode n = q.poll();
            if (n.left!=null) qNext.offer(n.left);
            if (n.right!=null) qNext.offer(n.right);
            if (q.isEmpty()){
                if (!qNext.isEmpty()){
                    count += qNext.size();
                    q = qNext;
                    qNext = new LinkedList<>();
                } else return count;
            }
        }
        return count;
    }

}
