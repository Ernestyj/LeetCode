
/**
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If nums = [1,2,2], a solution is:
 [ [2], [1], [1,2,2], [2,2], [1,2], [] ]
 * Created by DCLab on 1/11/2016.
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.size()<=0) return res;
        vector<int> sol;
        dfs(nums, res, sol, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& sol, int start){
        res.push_back(sol);
        for (int i = start; i < nums.size(); ++i) {
            if(i>start && nums[i]==nums[i-1]) continue;
            sol.push_back(nums[i]);
            dfs(nums, res, sol, i+1);
            sol.pop_back();
        }
    }
};
//public class SubsetsII {
//
//    public static void main(String[] args){
//        int[] nums = {1, 2, 2};
//        System.out.println("*****RESULT*****");
//        //法一
////        List<List<Integer>> res = new SubsetsII().subsetsWithDup(nums);
//        //法二
//        List<List<Integer>> res = new SubsetsII().subsetsWithDup1(nums);
//        //输出
//        for (List<Integer> ints : res){
//            for (Integer i : ints) System.out.print(i + " ");
//            System.out.println();
//        }
//    }
//
//    // 位图法：与Subsets位图法思路一致，再添加判重部分即可
//    public List<List<Integer>> subsetsWithDup(int[] nums) {
//        Arrays.sort(nums);
//        List<List<Integer>> result = new ArrayList<>();
//        List<Integer> temp;
//        int len = nums.length;
//        int n = 1 << len;
//        for (int i=0; i<n; i++){
//            temp = new ArrayList<>();
//            //查看第一层循环任意一种取值中哪一位是1；如果是1，对应的字符就存在
//            for (int k=1; k<=len; k++){
//                if ( (i&(1 << k-1)) != 0 ) temp.add(nums[k-1]);
//            }
//            if (!result.contains(temp)) //判重
//                result.add(new ArrayList<>(temp));
//        }
//        return result;
//    }
//
//    /**
//     * 回溯法
//     * 参考：http://bangbingsyb.blogspot.com/2014/11/leetcode-subsets-i-ii.html
//     * @param nums
//     * @return
//     */
//    public List<List<Integer>> subsetsWithDup1(int[] nums) {
//        Arrays.sort(nums);
//        List<List<Integer>> result = new ArrayList<>();
//        List<Integer> sol = new ArrayList<>();
//        result.add(sol);   //额外添加空集
//        backTrack(nums, 0, result, sol);
//        return result;
//    }
//    private void backTrack(int[] nums, int start, List<List<Integer>> result, List<Integer> sol){
//        for(int i=start; i<nums.length; i++) {
//            if (i>start && nums[i]==nums[i-1]) continue;    //跳过再次重复的数字
//            sol.add(nums[i]);
//            result.add(new ArrayList<>(sol));
//            backTrack(nums, i+1, result, sol);
//            sol.remove(sol.size() - 1);
//        }
//    }
//
//    //（有待细看）在原集合上添加数字构建子集的方法，参考http://www.programcreek.com/2013/01/leetcode-subsets-ii-java/
//    public List<List<Integer>> subsetsWithDup2(int[] nums) {
//        if (nums == null) return null;
//        Arrays.sort(nums);
//        List<List<Integer>> result = new ArrayList<>();
//        List<List<Integer>> prev = new ArrayList<>();
//        for (int i = nums.length-1; i >= 0; i--) {
//            //get existing sets
//            if (i == nums.length - 1 || nums[i] != nums[i + 1] || prev.size() == 0) {
//                prev = new ArrayList<>();
//                for (int j = 0; j < result.size(); j++) {
//                    prev.add(new ArrayList<>(result.get(j)));
//                }
//            }
//            //add current number to each element of the set
//            for (List<Integer> temp : prev) {
//                temp.add(0, nums[i]);
//            }
//            //add each single number as a set, only if current element is different with previous
//            if (i == nums.length - 1 || nums[i] != nums[i + 1]) {
//                ArrayList<Integer> temp = new ArrayList<>();
//                temp.add(nums[i]);
//                prev.add(temp);
//            }
//            //add all set created in this iteration
//            for (List<Integer> temp : prev) {
//                result.add(new ArrayList<>(temp));
//            }
//        }
//        //add empty set
//        result.add(new ArrayList<Integer>());
//        return result;
//    }
//
//}
