
/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
 return [1,3,2].
 Note: Recursive solution is trivial, could you do it iteratively?
 * Created by eugene on 16/1/15.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {//recursive
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }
    void inorderHelper(TreeNode* root, vector<int>& res){
        if(!root) return;
        inorderHelper(root->left, res);
        res.push_back(root->val);
        inorderHelper(root->right, res);
    }

    //迭代:从非空根节点开始入栈，只要存在左节点就一直入栈; 不存在左节点就出栈访问节点p，然后入栈p的非空右节点
    vector<int> inorderTraversal(TreeNode* root) {//traverse TODO 请熟背此方法
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;   //不需要先push root
        TreeNode* p = root;
        while (p || !stk.empty()){   //循环条件不仅仅是!stk.empty()
            if(p){
                stk.push(p);
                p = p->left;
            }else{
                p = stk.top();
                stk.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};
//public class BinaryTreeInorderTraversal {
//
//    //Definition for a binary tree node.
//    public class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//    /**
//     *递归:中序遍历左+访问根节点+中序遍历右
//     * @param root
//     * @return
//     */
//    public List<Integer> inorderTraversal(TreeNode root) {
//        List<Integer> result = new ArrayList<>();
//        inorderTraversalHelper(root, result);
//        return result;
//    }
//    private void inorderTraversalHelper(TreeNode root, List<Integer> result){
//        if (root == null) return;
//        inorderTraversalHelper(root.left, result);
//        result.add(root.val);
//        inorderTraversalHelper(root.right, result);
//    }
//
//
//
//    /**
//     * 迭代:从根节点开始入栈，只要存在左节点就一直入栈; 不存在左节点就出栈访问节点值，然后继续遍历出栈那个节点的右节点。
//     * @param root
//     * @return
//     */
//    public List<Integer> inorderTraversal1(TreeNode root) {
//        List<Integer> result = new ArrayList<>();
//        Stack<TreeNode> stack = new Stack();
//        TreeNode node = root;
//        while (true){
//            while (node != null){
//                stack.push(node);
//                node = node.left;
//            }
//            if (stack.isEmpty()) break;
//            node = stack.pop();
//            result.add(node.val);
//            node = node.right;
//        }
//        return result;
//    }
//
//}
