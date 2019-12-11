

/**Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 * Created by DCLab on 11/22/2015.
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        //sort(candidates.begin(), candidates.end());//TODO 不是必须的，如果candidates(without duplicates)
        dfs(candidates, target, res, sol, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& sol, int start){
        if(target==0){
            res.push_back(sol);
        }else if(target<0){
            return;
        }else{
            for (int i = start; i < candidates.size(); ++i) {
                sol.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], res, sol, i);
                sol.pop_back();
            }
        }
    }
};
//public class CombinationSum {
//
//    public List<List<Integer>> combinationSum(int[] candidates, int target) {
//        Set<List<Integer>> res = new HashSet<>();
//        dfs(candidates, target, res, new LinkedList<>(), 0);
//        return new LinkedList<>(res);
//    }
//    private void dfs(int[] candidates, int target, Set<List<Integer>> res, List<Integer> sol, int start){
//        if(target==0){
//            res.add(new LinkedList<>(sol));
//            return;
//        }
//        for(int i=start; i<candidates.length; i++){
//            if(target-candidates[i]>=0){
//                sol.add(candidates[i]);
//                dfs(candidates, target-candidates[i], res, sol, i);//TODO 这里是i
//                sol.remove(sol.size()-1);
//            }
//        }
//    }
//
//}
