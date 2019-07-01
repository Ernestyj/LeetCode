
/**
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
Determine the maximum amount of money the thief can rob tonight without alerting the police.
Example 1:
Input: [3,2,3,null,3,null,1]
     3
    / \
   2   3
    \   \
     3   1
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
Input: [3,4,5,1,3,null,1]
     3
    / \
   4   5
  / \   \
 1   3   1
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int rob(TreeNode* root) {//递归分析root, root->left, root->right之间的相邻关系
        vector<int> res = dfs(root);
        return max(res[0], res[1]); //res[0]表示不包含当前节点值的最大值，res[1]表示包含当前值的最大值

    }
    vector<int> dfs(TreeNode* root){
        if(!root) return vector<int>{0, 0};
        vector<int> l = dfs(root->left);    //首先对其左右子节点调用递归函数，分别得到包含与不包含左子节点值的最大值，和包含于不包含右子节点值的最大值
        vector<int> r = dfs(root->right);
        vector<int> res{0, 0};
        res[0] = max(l[0], l[1]) + max(r[0], r[1]);
        res[1] = l[0] + r[0] + root->val;
        return res;
    }
};
