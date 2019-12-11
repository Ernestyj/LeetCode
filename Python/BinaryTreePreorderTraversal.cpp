
/**Given a binary tree, return the preorder traversal of its nodes' values.
 For example: Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
 return [1,2,3].
 Note: Recursive solution is trivial, could you do it iteratively?
 * Created by eugene on 16/3/3.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) { //dfs
        vector<int> res;
        if(!root) return res;
        preorderDFS(root, res);
        return res;
    }
    void preorderDFS(TreeNode* root, vector<int>& res){
        if(!root) return;
        res.push_back(root->val);
        preorderDFS(root->left, res);
        preorderDFS(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) { //iterate
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while (p || !stk.empty()){
            if(p){
                stk.push(p);
                res.push_back(p->val);
                p = p->left;
            }else{
                TreeNode* node = stk.top();
                stk.pop();
                p = node->right;
            }
        }
        return res;
    }
};
//public class BinaryTreePreorderTraversal {
//
//    public class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//
//    public List<Integer> preorderTraversal(TreeNode root) {
//        List<Integer> result = new ArrayList<>();
//        if (root==null) return result;
//        Stack<TreeNode> stack = new Stack<>();
//        stack.push(root);
//        while (!stack.isEmpty()){
//            TreeNode node = stack.pop();
//            result.add(node.val);
//            if (node.right!=null) stack.push(node.right);
//            if (node.left!=null) stack.push(node.left);
//        }
//        return result;
//    }
//
//}
