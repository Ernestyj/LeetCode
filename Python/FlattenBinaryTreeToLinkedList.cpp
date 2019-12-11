
/**Given a binary tree, flatten it to a linked list in-place.
 * Created by eugene on 16/2/2.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    // 把二叉树展开成链表，根据展开后形成的链表的顺序分析出是使用先序遍历，那么只要是数的遍历就有递归和非递归的两种方法来求解。
    // 首先来看递归版本的，思路是先利用DFS的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，
    // 然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。代码如下：
    /**
     1
    / \
   2   5
  / \   \
 3   4   6

     1
    / \
   2   5
    \   \
     3   6
      \
       4

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
     */
    void flatten(TreeNode *root) {
            if (!root) return;
            if (root->left) flatten(root->left);
            if (root->right) flatten(root->right);
            TreeNode *tmp = root->right;
            root->right = root->left;
            root->left = NULL;
            while (root->right) root = root->right;
            root->right = tmp;
    }

public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
private:
    TreeNode* pre = nullptr;
};
//public class FlattenBinaryTreeToLinkedList {
//    //Definition for a binary tree node.
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//
//    private TreeNode prev = null;
//    /**
//     * https://leetcode.com/discuss/30719/my-short-post-order-traversal-java-solution-for-share
//     */
//    public void flatten(TreeNode root) {
//        if (root == null) return;
//        flatten(root.right);
//        flatten(root.left);
//        root.right = prev;
//        root.left = null;
//        prev = root;
//    }
//
//    /**
//     * dfs,先序
//     * @param root
//     */
//    public void flatten1(TreeNode root) {
//        List<TreeNode> preOrderList = new ArrayList<>();
//        preOrderTraversal(preOrderList, root);
//        for (int i=0; i<preOrderList.size()-1; i++){
//            TreeNode node = preOrderList.get(i);
//            node.left = null;
//            node.right = preOrderList.get(i+1);
//        }
//    }
//    private void preOrderTraversal(List<TreeNode> preOrderList, TreeNode root){
//        if (root==null) return;
//        preOrderList.add(root);
//        preOrderTraversal(preOrderList, root.left);
//        preOrderTraversal(preOrderList, root.right);
//    }
//
//}
