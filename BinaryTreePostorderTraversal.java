package leetcode141_150;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**Given a binary tree, return the postorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
 return [3,2,1].
 Note: Recursive solution is trivial, could you do it iteratively?
 * Created by eugene on 16/3/4.
 */
public class BinaryTreePostorderTraversal {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**TODO 重温记忆
     * 后序遍历的情况相对复杂,需要维护当前遍历的cur指针和前一个遍历的pre指针来追溯当前的情况
     （注意这里是遍历的指针，并不是真正按后序访问顺序的结点）。具体分为几种情况：
     （1）如果pre的左孩子或者右孩子是cur，那么说明遍历在往下走，按访问顺序继续，
     即如果有左孩子，则是左孩子进栈，否则如果有右孩子，则是右孩子进栈，
     如果左右孩子都没有，则说明该结点是叶子，可以直接访问并把结点出栈了。
     （2）如果反过来，cur的左孩子是pre，则说明已经在回溯往上走了，
     但是后序遍历要左右孩子走完才可以访问自己，所以这里如果有右孩子还需要把右孩子进栈，
     否则说明已经到自己了，可以访问并且出栈了。
     （3）如果cur的右孩子是pre，那么说明左右孩子都访问结束了，可以轮到自己了，访问并且出栈即可。
     与递归法一样,算法时间复杂度也是O(n)，空间复杂度是栈的大小O(logn)。
     * http://www.programcreek.com/2012/12/leetcode-solution-of-iterative-binary-tree-postorder-traversal-in-java/
     * @param root
     * @return
     */
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root==null) return result;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        TreeNode prev = null;
        while (!stack.isEmpty()){
            TreeNode curr = stack.peek();
            if (prev==null || prev.left==curr || prev.right==curr){ //往下走
                if (curr.left!=null) stack.push(curr.left);
                else if (curr.right!=null) stack.push(curr.right);
                else {
                    stack.pop();
                    result.add(curr.val);
                }
            } else if (curr.left==prev){    //从左节点往上走
                if (curr.right!=null) stack.push(curr.right);
                else {
                    stack.pop();
                    result.add(curr.val);
                }
            } else if (curr.right==prev){   //从右节点往上走
                stack.pop();
                result.add(curr.val);
            }
            prev = curr;
        }
        return result;
    }

    //这种方法简单,但是会改变原树结构
    public List<Integer> postorderTraversal1(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) return list;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (stack.size() != 0){
            TreeNode top = stack.peek();
            if (top.left == null && top.right == null){
                list.add(top.val);
                stack.pop();
            }
            if (top.left != null){
                stack.push(top.left);
                top.left = null;
                continue;
            }
            if (top.right != null){
                stack.push(top.right);
                top.right = null;
                continue;
            }
        }
        return list;
    }

}
