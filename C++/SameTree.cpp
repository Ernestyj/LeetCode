
/**
 * Given two binary trees, write a function to check if they are equal or not.
 Two binary trees are considered equal if they are structurally identical and
 the nodes have the same value.
 * Created by eugene on 16/1/20.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        else if(p != nullptr && q != nullptr){
            if(p->val == q->val){
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
        return false;
    }
};

//public class SameTree {
//
//    //Definition for a binary tree node.
//    public static class TreeNode {
//        int val;
//        TreeNode left;
//        TreeNode right;
//        TreeNode(int x) { val = x; }
//    }
//
//
//    public boolean isSameTree(TreeNode p, TreeNode q) {
//        if(p == null && q == null) return true;
//        else if(p != null && q != null){
//            if(p.val == q.val)
//                return isSameTree(p.left, q.left) && isSameTree(q.right, p.right);
//        }else return false;
//        return false;
//    }
//
//
//    public boolean isSameTree1(TreeNode p, TreeNode q) {
//        if (p==null && q==null) return true;
//        List<Integer> pInts = new ArrayList<>();
//        List<Integer> qInts = new ArrayList<>();
//        inOrderTraverse(p, pInts, true);
//        inOrderTraverse(q, qInts, false);
//        if (pInts.size() != qInts.size()) return false;
//        for (int i=0; i<pInts.size(); i++){
//            if ((int)pInts.get(i) != (int)qInts.get(i)) {
//                return false;   //TODO Integer.MIN_VALUE != Integer.MIN_VALUE 必须转成int
//            }
//        }
//        return true;
//    }
//    private void inOrderTraverse(TreeNode root, List<Integer> ints, boolean isLeft){
//        if (root == null) {
//            if (isLeft) ints.add(Integer.MIN_VALUE);
//            else ints.add(Integer.MAX_VALUE);
//            return;
//        }
//        inOrderTraverse(root.left, ints, true);
//        ints.add(root.val);
//        inOrderTraverse(root.right, ints, false);
//    }
//
//}
