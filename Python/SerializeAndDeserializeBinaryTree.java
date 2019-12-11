package leetcode291_300;

import java.util.ArrayDeque;
import java.util.LinkedList;

/**Serialization is the process of converting a data structure or object into a sequence of bits so that
 it can be stored in a file or memory buffer, or transmitted across a network connection link to be
 reconstructed later in the same or another computer environment.

 Design an algorithm to serialize and deserialize a binary tree. There is no restriction on
 how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree
 can be serialized to a string and this string can be deserialized to the original tree structure.

 Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 * Created by eugene on 16/5/30.
 */
public class SerializeAndDeserializeBinaryTree {

    //Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    //另一种方法是按先序遍历顺序(递归),https://leetcode.com/discuss/66117/easy-to-understand-java-solution

    /**
     * 层次法
     * https://leetcode.com/discuss/73461/short-and-straight-forward-bfs-java-code-with-a-queue
     */
    public class Codec {
        // Encodes a tree to a single string.
        public String serialize(TreeNode root) {
            if (root==null) return "";
            LinkedList<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            StringBuilder builder = new StringBuilder();
            while (!queue.isEmpty()){
                TreeNode node = queue.poll();
                if (node==null) builder.append("n,");   //null节点用"n"标记
                else {
                    builder.append(node.val+",");
                    queue.offer(node.left);
                    queue.offer(node.right);
                }
            }
            return builder.toString();
        }

        // Decodes your encoded data to tree.
        public TreeNode deserialize(String data) {
            if (data.equals("")) return null;
            String[] strings = data.split(",");
            LinkedList<TreeNode> queue = new LinkedList<>();    //队列存非空父节点
            TreeNode root = new TreeNode(Integer.valueOf(strings[0]));
            queue.offer(root);
            for (int i=1; i<strings.length; i++){
                TreeNode p = queue.poll();
                if (!strings[i].equals("n")){
                    TreeNode left = new TreeNode(Integer.valueOf(strings[i]));
                    p.left = left;
                    queue.offer(left);
                }
                if (!strings[++i].equals("n")){
                    TreeNode right = new TreeNode(Integer.valueOf(strings[i]));
                    p.right = right;
                    queue.offer(right);
                }
            }
            return root;
        }
    }

}
