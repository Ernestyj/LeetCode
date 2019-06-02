
/**
 * 4Sum:
 * Given an array S of n integers, are there elements a, b, c, and d in S
 * such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * A solution set is:
     (-1,  0, 0, 1)
     (-2, -1, 1, 2)
     (-2,  0, 0, 2)
 *
 * Created by DCLab on 10/31/2015.
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for (int j = i+1; j < nums.size() - 2; ++j) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l = j+1, r = nums.size()-1;
                while(l<r){
                    int sum = nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l<r && nums[l]==nums[l+1]) ++l;
                        while(l<r && nums[r]==nums[r-1]) --r;
                        ++l;
                        --r;
                    }
                    else if(sum>target) --r;
                    else ++l;
                }
            }
        }
        return res;
    }
};
//public class FourSum {
//
//    /**
//     * 时间复杂度 n^3 （nlogn + n^2 * n）
//     * 先快排，再枚举第一个、第二个数，然后对余下数的求2sum(注意去重)
//     * @param nums
//     * @param target
//     * @return
//     */
//    public List<List<Integer>> fourSum(int[] nums, int target) {
//        ArrayList<List<Integer>> res = new ArrayList<>();
//        if(nums.length<4) return res;
//        Arrays.sort(nums);
//        for(int i=0; i<nums.length-3; i++){
//            if(i>0 && nums[i]==nums[i-1]) continue; // Skip same results
//            for(int j=i+1; j<nums.length-2; j++){
//                if(j>i+1 && nums[j]==nums[j-1]) continue; // Skip same results
//                int l = j+1, r = nums.length-1;
//                while(l<r){
//                    int sum = nums[i]+nums[j]+nums[l]+nums[r];
//                    if(sum==target){
//                        res.add(Arrays.asList(nums[i], nums[j], nums[l], nums[r]));
//                        while(l<r && nums[l]==nums[l+1]) l++;   // Skip same results
//                        while(l<r && nums[r]==nums[r-1]) r--;   // Skip same results
//                        l++; r--;
//                    } else if(sum<target)l++;
//                    else r--;
//                }
//            }
//        }
//        return res;
//    }
//
//}
