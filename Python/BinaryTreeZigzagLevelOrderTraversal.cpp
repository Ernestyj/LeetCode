
/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 For example: Given binary tree {3,9,20,#,#,15,7},
 return its zigzag level order traversal as: [ [3], [20,9], [15,7] ]
 * Created by eugene on 16/1/23.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool lToR = true;
        while (!q.empty()){
            int n = q.size();
            list<int> sol;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(lToR) sol.push_back(node->val);
                else sol.push_front(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.emplace_back(sol.begin(), sol.end());
            lToR = !lToR;
        }
        return res;
    }
};
//public class BinaryTreeZigzagLevelOrderTraversal {
//    //Definition for a binary tree node.
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//    //简洁
//    public List<List> zigzagLevelOrder(TreeNode root) {
//        List<List> res = new ArrayList<>();
//        if(root == null) return res;
//        Queue<TreeNode> q = new LinkedList<>();
//        q.add(root);
//        boolean order = true;
//        int size = 1;
//        while(!q.isEmpty()) {
//            List<Integer> tmp = new ArrayList<>();
//            for(int i = 0; i < size; ++i) {
//                TreeNode n = q.poll();
//                if(order) tmp.add(n.val);
//                else tmp.add(0, n.val);
//                if(n.left != null) q.add(n.left);
//                if(n.right != null) q.add(n.right);
//            }
//            res.add(tmp);
//            size = q.size();
//            order = !order;
//        }
//        return res;
//    }
//
//    public List<List<Integer>> zigzagLevelOrder1(TreeNode root) {
//        List<List<Integer>> result = new ArrayList<>();
//        List<Integer> temp = new ArrayList<>();
//        boolean needReverse = false;
//        if (root==null) return result;
//        Stack<TreeNode> curStack = new Stack<>();
//        Stack<TreeNode> nextStack = new Stack<>();
//        curStack.push(root);
//        while (!curStack.isEmpty()){
//            TreeNode node = curStack.pop();
//            temp.add(node.val);
//            if (needReverse) {
//                if (node.right!=null) nextStack.push(node.right);
//                if (node.left!=null) nextStack.push(node.left);
//            } else {
//                if (node.left!=null) nextStack.push(node.left);
//                if (node.right!=null) nextStack.push(node.right);
//            }
//            if (curStack.isEmpty()) {
//                result.add(temp);
//                temp = new ArrayList<>();
//                needReverse = !needReverse;
//                curStack = nextStack;
//                nextStack = new Stack<>();
//            }
//        }
//        return result;
//    }
//
//}
