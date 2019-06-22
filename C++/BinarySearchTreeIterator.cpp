
/**Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 Calling next() will return the next smallest number in the BST.
 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * Created by eugene on 16/3/21.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
    //从根节点开始入栈，只要存在左节点就一直入栈; 不存在左节点就出栈访问节点值，然后继续遍历出栈那个节点的右节点。
    BSTIterator(TreeNode* root) {
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
    /** @return the next smallest number */
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        int res = node->val;
        node = node->right; //不存在左节点就出栈访问节点值，然后继续遍历出栈那个节点的右节点
        if(node){
            while (node){
                stk.push(node); //入栈右或左节点
                node = node->left;  //只要存在左节点就一直入栈
            }
        }
        return res;
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
private:
    stack<TreeNode*> stk;
};
//public class BSTIterator {
//    //空间复杂度O(h)
//    private Stack<TreeNode> stack = null;
//    //从根节点开始入栈，只要存在左节点就一直入栈; 不存在左节点就出栈访问节点值，然后继续遍历出栈那个节点的右节点。
//    public BSTIterator(TreeNode root) {
//        stack = new Stack<>();
//        while (root!=null){
//            stack.push(root);
//            root = root.left;
//        }
//    }
//    /** @return whether we have a next smallest number */
//    public boolean hasNext() {
//        return !stack.isEmpty();
//    }
//    /** @return the next smallest number */
//    public int next() {
//        TreeNode node = stack.pop();
//        int result = node.val;
//        if (node.right!=null){
//            node = node.right;
//            while (node!=null){
//                stack.push(node);
//                node = node.left;
//            }
//        }
//        return result;
//    }
//
//}

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
