package leetcode251_260;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;

/**Given a binary tree, return all root-to-leaf paths.
 For example, given the following binary tree:
   1
 /   \
 2     3
 \
 5
 All root-to-leaf paths are: ["1->2->5", "1->3"]
 * Created by eugene on 16/5/10.
 */
public class BinaryTreePaths {

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**
     * https://leetcode.com/discuss/52072/accepted-java-simple-solution-in-8-lines
     * @param root
     * @return
     */
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<>();
        if (root!=null) searchBT(root, "", result);
        return result;
    }
    private void searchBT(TreeNode root, String path, List<String> result) {
        if (root.left==null && root.right==null) result.add(path+root.val);
        if (root.left!=null) searchBT(root.left, path+root.val+"->", result);
        if (root.right!=null) searchBT(root.right, path+root.val+"->", result);
    }


    //迭代式先序遍历,失败
    public List<String> binaryTreePaths1(TreeNode root) {
        List<String> result = new ArrayList<>();
        List<TreeNode> stack = new ArrayList<>();
        TreeNode p = root;
        while (!stack.isEmpty() || p!=null){
            if (p!=null){
                stack.add(p);
                if (p.left==null && p.right==null) result.add(getPath(stack));
                p = p.left;
            } else {
                TreeNode node = stack.remove(stack.size()-1);
                p = node.right;
            }
        }
        return result;
    }
    private String getPath(List<TreeNode> stack){
        StringBuilder builder = new StringBuilder();
        for (TreeNode p: stack){
            builder.append(p.val+"->");
        }
        return builder.substring(0, builder.length()-2);
    }

}
