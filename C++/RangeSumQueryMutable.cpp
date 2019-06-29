
/**Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 The update(i, val) function modifies nums by updating the element at index i to val.
 Example:
 Given nums = [1, 3, 5]
 sumRange(0, 2) -> 9
 update(1, 2)
 sumRange(0, 2) -> 8
 Note:
 The array is only modifiable by the update function.
 You may assume the number of calls to update and sumRange function is distributed evenly.
 * Created by eugene on 16/6/9.
 */
class NumArray {//各种题解https://www.cnblogs.com/grandyang/p/4985506.html  线段树https://www.jianshu.com/p/91f2c503e62f
public:
    NumArray(vector<int>& nums) {
        root = build(nums, 0, nums.size()-1);
    }
    void update(int i, int val) {
        update(root, i, val);
    }
    int sumRange(int i, int j) {
        return query(root, i, j);
    }
private:
    //Segment Tree, 递归构建/更新/查询. O(n) build， O(logn) update, O(logn) rangeSum，  Space Complexity - O(n)
    struct SegTreeNode{
        int l, r, sum;
        SegTreeNode* left, *right;
        SegTreeNode(int l, int r): l(l), r(r), sum(0), left(nullptr), right(nullptr){}
    };
    SegTreeNode* root;
    SegTreeNode* build(vector<int>& nums, int start, int end){
        if(start>end) return nullptr;
        else {
            SegTreeNode* node = new SegTreeNode(start, end);    //TODO 注意此处不能将sum赋值为nums[start]
            if(start==end) node->sum = nums[start];
            else{
                int m = start+(end-start)/2;
                node->left = build(nums, start, m);
                node->right = build(nums, m+1, end);
                node->sum = node->left->sum + node->right->sum;
            }
            return node;
        }
    }
    void update(SegTreeNode* root, int i, int val){
        if(root->l==root->r && root->l==i) root->sum = val; //TODO 此处执行完应返回，要不return，要不下面接着写else
        else{
            int m = root->l + (root->r-root->l)/2;
            if(i<=m) update(root->left, i, val);
            else update(root->right, i, val);
            root->sum = root->left->sum + root->right->sum;
        }
    }
    int query(SegTreeNode* root, int start, int end){
        if(start==root->l && root->r==end) return root->sum;
        else {
            int m = root->l + (root->r-root->l)/2;
            if(end<=m) return query(root->left, start, end);
            else if(m+1<=start) return query(root->right, start, end);
            else return query(root->left, start, m)+query(root->right, m+1, end);   //区间交错
        }
    }
};
//public class RangeSumQueryMutable {
//    /**https://leetcode.com/discuss/70202/17-ms-java-solution-with-segment-tree
//     * Segment Tree, 递归构建/更新/查询 O(n) build， O(logn) update, O(logn) rangeSum，  Space Complexity - O(n)
//     */
//    public class NumArray {
//
//        class SegmentTreeNode {
//            int l, r;
//            SegmentTreeNode left, right;
//            int sum;
//            public SegmentTreeNode(int beg, int end) {
//                this.l = beg;
//                this.r = end;
//                this.left = null;
//                this.right = null;
//                this.sum = 0;
//            }
//        }
//
//        SegmentTreeNode root = null;
//
//        public NumArray(int[] nums) {
//            root = buildTree(nums, 0, nums.length-1);
//        }
//        private SegmentTreeNode buildTree(int[] nums, int beg, int end) {
//            if (beg > end) {
//                return null;
//            } else {
//                SegmentTreeNode ret = new SegmentTreeNode(beg, end);
//                if (beg == end) {
//                    ret.sum = nums[beg];
//                } else {
//                    int m = beg  + (end - beg) / 2;
//                    ret.left = buildTree(nums, beg, m);
//                    ret.right = buildTree(nums, m + 1, end);
//                    ret.sum = ret.left.sum + ret.right.sum;
//                }
//                return ret;
//            }
//        }
//
//        public void update(int i, int val) {
//            update(root, i, val);
//        }
//        private void update(SegmentTreeNode root, int pos, int val) {
//            if (root.l == root.r) {
//                root.sum = val;
//            } else {
//                int m = root.l + (root.r - root.l) / 2;
//                if (pos <= m) {
//                    update(root.left, pos, val);
//                } else {
//                    update(root.right, pos, val);
//                }
//                root.sum = root.left.sum + root.right.sum;
//            }
//        }
//
//        public int sumRange(int i, int j) {
//            return sumRange(root, i, j);
//        }
//        private int sumRange(SegmentTreeNode root, int beg, int end) {
//            if (root.r == end && root.l == beg) {
//                return root.sum;
//            } else {
//                int m = root.l + (root.r - root.l) / 2;
//                if (end <= m) {
//                    return sumRange(root.left, beg, end);
//                } else if (beg >= m+1) {
//                    return sumRange(root.right, beg, end);
//                }  else {
//                    return sumRange(root.right, m+1, end) + sumRange(root.left, beg, m);
//                }
//            }
//        }
//    }
//}
