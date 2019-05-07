package leetcode171_180;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 Calling next() will return the next smallest number in the BST.
 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * Created by eugene on 16/3/21.
 */
public class BSTIterator {
    //空间复杂度O(h)
    private Stack<TreeNode> stack = null;
    //从根节点开始入栈，只要存在左节点就一直入栈;
    //不存在左节点就出栈访问节点值，然后继续遍历出栈那个节点的右节点。
    public BSTIterator(TreeNode root) {
        stack = new Stack<>();
        while (root!=null){
            stack.push(root);
            root = root.left;
        }
    }
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !stack.isEmpty();
    }
    /** @return the next smallest number */
    public int next() {
        TreeNode node = stack.pop();
        int result = node.val;
        if (node.right!=null){
            node = node.right;
            while (node!=null){
                stack.push(node);
                node = node.left;
            }
        }
        return result;
    }

}

//空间复杂度O(n)
class BSTIterator1 {

    private int index = 0;
    private List<TreeNode> nodes = new ArrayList<>();
    public BSTIterator1(TreeNode root) {
        inOrderTraverse(root);
    }
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return nodes.size()-index>0? true : false;
    }
    /** @return the next smallest number */
    public int next() {
        return nodes.get(index++).val;
    }

    private void inOrderTraverse(TreeNode root){
        if (root==null) return;
        inOrderTraverse(root.left);
        nodes.add(root);
        inOrderTraverse(root.right);
    }

}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
