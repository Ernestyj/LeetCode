
/**
 * Given n, generate all structurally unique BST's (binary search trees) that
 store values 1...n.
 * Created by eugene on 16/1/16.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    // dfs+DP, 带记忆数组的递归形式就是 DP 的一种，memo[i][j] 表示在区间 [i, j] 范围内可以生成的所有 BST 的根结点，
    // 所以 memo 必须是一个三维数组，这样在递归函数中，我们就可以去 memo 中查找当前的区间是否已经计算过了，
    // 是的话，直接返回 memo 中的数组，否则就按之前的方法去计算，最后计算好了之后要更新 memo 数组
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        return helper(1, n, memo);
    }
    vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& memo) {
        if (start > end) return {nullptr};
        if (!memo[start - 1][end - 1].empty()) return memo[start - 1][end - 1];
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            auto left = helper(start, i - 1, memo), right = helper(i + 1, end, memo);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode *node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return memo[start - 1][end - 1] = res;
    }

    vector<TreeNode*> generateTrees(int n) {//dfs, 不带记忆
        if(n==0) return vector<TreeNode*>();
        return genTrees(1, n);
    }
    vector<TreeNode*> genTrees(int start, int end){
        vector<TreeNode*> res;
        if(start>end) res.push_back(nullptr);
        else if(start==end) res.push_back(new TreeNode(start));
        else{
            for (int i = start; i <= end; ++i) {
                vector<TreeNode*> left = genTrees(start, i-1);
                vector<TreeNode*> right = genTrees(i+1, end);
                for(auto l: left){
                    for(auto r: right){
                        TreeNode* root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
//public class UniqueBinarySearchTreesII {
//    //Definition for a binary tree node.
//    public class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) {
//            val = x;
//        }
//    }
//    /**https://leetcode.com/discuss/10254/a-simple-recursive-solution
//     * DP与回溯:在循环中进行递归,类似NQueens.
//     * I start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n.
//     So if I pick i-th node as my root, the left subtree will contain elements 1 to (i-1),
//     and the right subtree will contain elements (i+1) to n. I use recursive calls to get back all
//     possible trees for left and right subtrees and combine them in all possible ways with the root.
//     */
//    public List<TreeNode> generateTrees(int n) {
//        if (n==0) return new ArrayList<>();
//        return genTrees(1, n);
//    }
//    private List<TreeNode> genTrees(int start, int end) {
//        List<TreeNode> list = new ArrayList<>();
//        if(start>end) {
//            list.add(null);
//            return list;
//        } else if(start==end){
//            list.add(new TreeNode(start));
//            return list;
//        }
//        for(int i=start;i<=end;i++) {
//            List<TreeNode> left = genTrees(start, i-1);
//            List<TreeNode> right = genTrees(i+1, end);
//            for(TreeNode l: left) {
//                for(TreeNode r: right) {
//                    TreeNode root = new TreeNode(i);
//                    root.left = l;
//                    root.right = r;
//                    list.add(root);
//                }
//            }
//        }
//        return list;
//    }
//
//}
