
/**
 * 用线段树来解决: 对区间的一个点的值进行修改; 对区间的一段值进行统一的修改; 询问区间的和; 询问区间的最大值、最小值
如果我们删除或者增加区间中的元素，那么区间的大小将发生变化，此时是无法使用线段树解决这种问题的。
 */
//c++ leetcode Range Sum Query Mutable示例
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


//java 线段树(max)
public class SegmentTreeNode {  // 节点区间定义(with max)   https://www.jianshu.com/p/91f2c503e62f
    public int start, end, max; // [start, end] 代表节点的区间范围; max 是节点在(start,end)区间上的最大值
    public SegmentTreeNode left, right; // left , right 是当前节点区间划分之后的左右节点区间
    public SegmentTreeNode(int start, int end, int max) {
        this.start = start;
        this.end = end;
        this.max = max
        this.left = this.right = null;
    }
}
public SegmentTreeNode build(int[] A) { // 构造的代码及注释
    return buildhelper(0, A.length - 1, A);
}
public SegmentTreeNode buildhelper(int start, int end, int[] A){
    if(start > end) return null;
    SegmentTreeNode root = new SegmentTreeNode(start, end, A[start]); // 根据节点区间的左边界的序列值为节点赋初值
    if(start == end) return root; // 如果左边界和右边界相等,节点左边界的序列值就是线段树节点的接节点值
    int mid = (start + end) / 2; // 划分当前区间的左右区间
    root.left = buildhelper(start, mid, A);
    root.right = buildhelper(mid + 1, end, A);
    root.max = Math.max(root.left.max, root.right.max); // 根据节点区间的左右区间的节点值得到当前节点的节点值
    return root;
}
public void modify(SegmentTreeNode root, int index, int value) {    // 单点更新的代码及注释
    if(root.start == root.end && root.start == index) { // 找到被改动的叶子节点
        root.max = value; // 改变value值
        return ;
    }
    int mid = (root.start + root.end) / 2; // 将当前节点区间分割为2个区间的分割线
    if(index <= mid){ // 如果index在当前节点的左边
        modify(root.left, index, value);
        root.max = Math.max(root.right.max, root.left.max); // 可能对当前节点的影响
    } else {            // 如果index在当前节点的右边
        modify(root.right, index, value);
        root.max = Math.max(root.left.max, root.right.max); // 可能对当前节点的影响
    }
    return ;
}
// 区间查询的代码及注释
public int query(TreeNode root, int start, int end) {
    if (start <= root.start && root.end <= end) return root.max;    // 如果查询区间在当前节点的区间之内,直接输出结果 TODO ?
    int mid = (root.start + root.end) / 2; // 将当前节点区间分割为左右2个区间的分割线
    int ans = Integer.MIN_VALUE; // 给结果赋初值
    if (mid >= start) {   // 如果查询区间和左边节点区间有交集,则寻找查询区间在左边区间上的最大值
        ans = Math.max(ans, query(root.left, start, end));
    }
    if (mid + 1 <= end) { // 如果查询区间和右边节点区间有交集,则寻找查询区间在右边区间上的最大值
        ans = Math.max(ans, query(root.right, start, end));
    }
    return ans; // 返回查询结果
}



