package leetcode191_200;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 * https://leetcode.com/problems/binary-tree-right-side-view/
 * Created by eugene on 16/3/29.
 */
public class BinaryTreeRightSideView {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root==null) return result;
        Queue<TreeNode> q = new LinkedList<>();
        Queue<TreeNode> qNext = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()){
            TreeNode n = q.poll();
            if (n.left!=null) qNext.offer(n.left);
            if (n.right!=null) qNext.offer(n.right);
            if (q.isEmpty()){
                result.add(n.val);
                if (!qNext.isEmpty()){
                    q = new LinkedList<>(qNext);
                    qNext = new LinkedList<>();
                }
            }
        }
        return result;
    }

    //速度优化
    public List<Integer> rightSideView1(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        if(root == null) return result;
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while(queue.size() > 0){
            //get size here
            int size = queue.size();
            for(int i=0; i<size; i++){
                TreeNode top = queue.remove();
                //the first element in the queue (right-most of the tree)
                if(i==0){
                    result.add(top.val);
                }
                if(top.right != null){
                    queue.add(top.right);
                }
                if(top.left != null){
                    queue.add(top.left);
                }
            }
        }
        return result;
    }

}
