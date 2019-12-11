
/**Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 return its level order traversal as: [ [3], [9,20], [15,7] ]
 * Created by eugene on 16/1/22.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {//bfs
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            vector<int> sol;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sol.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(sol);
        }
        return res;
    }
};
//public class BinaryTreeLevelOrderTraversal {
//
//    //Definition for a binary tree node.
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//    /**
//     * 广度优先搜索，使用队列实现。
//     */
//    public List<List<Integer>> levelOrder(TreeNode root) {
//        List<List<Integer>> res = new LinkedList<>();
//        if(root == null) return res;
//        LinkedList<TreeNode> q = new LinkedList<>();
//        q.offer(root);
//        while(!q.isEmpty()){
//            int n = q.size();
//            List<Integer> list = new LinkedList<>();
//            for(int i=0; i<n; i++) {
//                TreeNode node = q.poll();
//                if(node.left != null) q.offer(node.left);
//                if(node.right != null) q.offer(node.right);
//                list.add(node.val);
//            }
//            res.add(list);
//        }
//        return res;
//    }
//
//}
