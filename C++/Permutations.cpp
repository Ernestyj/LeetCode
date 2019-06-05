

/**
 * Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 * Created by DCLab on 11/29/2015.
 */
class Solution {//TODO 不含重复
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<=0) return res;
        dfs(nums, 0, res);
        return res;
    }
    void dfs(vector<int>& nums, int start, vector<vector<int>>& res){
        if(start==nums.size()){//TODO 不是start==nums.size()-1
            res.push_back(nums);
        }else{
            for (int i = start; i < nums.size(); ++i) {
                swap(nums[i], nums[start]);
                dfs(nums, start+1, res);    //TODO 注意特殊的地方,不是i+1而是start+1
                swap(nums[i], nums[start]);
            }
        }
    }
};
//public class Permutations {
//
//    /**TODO 不含重复
//     * 回溯法：从集合依次选出每一个元素，作为排列的第一个元素，然后对剩余的元素进行全排列，如此递归处理。
//     * 时间复杂度：n! 空间复杂度：（in place置换）
//     * 以abc为例子：
//     1. a和a交换(固定a), 求后面bc的全排列： abc, acb。 求完后，a和b交换； 得到bac,开始第二轮
//     2. b和b交换(固定b), 求后面ac的全排列： bac, bca。 求完后，b和c交换； 得到cab,开始第三轮
//     3. c和c交换(固定c), 求后面ba的全排列： cab, cba.
//     * http://blog.csdn.net/randyjiawenjie/article/details/6313729
//     * 分析图：http://segmentfault.com/a/1190000002710424
//     * @param nums
//     */
//    public List<List<Integer>> permute(int[] nums) {
//        List<List<Integer>> res = new LinkedList<>();
//        dfs(nums, res, 0);
//        return res;
//    }
//    private void dfs(int[] nums, List<List<Integer>> res, int start){
//        if(start==nums.length){
//            List<Integer> sol = new LinkedList<>();
//            for(int n: nums) sol.add(n);
//            res.add(sol);
//            return;
//        }
//        for(int i=start; i<nums.length; i++){
//            swap(nums, start, i);
//            dfs(nums, res, start+1);    //TODO 注意特殊的地方,不是i+1而是start+1
//            swap(nums, start, i);
//        }
//    }
//    private void swap(int[] nums, int i, int j){
//        int temp = nums[i];
//        nums[i] = nums[j];
//        nums[j] = temp;
//    }
//
//
//    /**https://leetcode.com/discuss/29483/share-my-short-iterative-java-solution
//     * tricky 复制插入方法,类似subsets中的复制插入方法,但更不易理解
//     * @param nums
//     * @return
//     */
//    public List<List<Integer>> permute1(int[] nums) {
//        LinkedList<List<Integer>> res = new LinkedList<>();
//        res.add(new ArrayList<>());
//        for (int num : nums) {
//            int n = res.size();
//            for (int k=0; k<n; k++) {
//                List<Integer> sol = res.poll();
//                for (int i=0; i<=sol.size(); i++) {
//                    List<Integer> nSol = new ArrayList<>(sol);
//                    nSol.add(i, num);
//                    res.add(nSol);
//                }
//            }
//        }
//        return res;
//    }
//
//}
