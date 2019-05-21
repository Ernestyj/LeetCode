
/**Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * Created by eugene on 16/1/27.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l>r) return nullptr;
        int m = l+(r-l)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = helper(nums, l, m-1);
        root->right = helper(nums, m+1, r);
        return root;
    }
};
//public class ConvertSortedArrayToBinarySearchTree {
//
//    //Definition for a binary tree node.
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//
//    /**
//     * 递归:类似二分搜索.因为中序序列的中间数为根.
//     * @param nums
//     * @return
//     */
//    public TreeNode sortedArrayToBST(int[] nums) {
//        if (nums.length == 0) return null;
//        return sortedArrayToBST(nums, 0, nums.length-1);
//    }
//    private TreeNode sortedArrayToBST(int[] nums, int l, int r){
//        if (l>r) return null;
//        int m = (l+r)/2;
//        TreeNode root = new TreeNode(nums[m]);
//        root.left = sortedArrayToBST(nums, l, m-1);
//        root.right = sortedArrayToBST(nums, m+1, r);
//        return root;
//    }
//
//}
