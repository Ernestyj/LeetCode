
/**Given a collection of candidate numbers (candidates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
 * Created by DCLab on 11/23/2015.
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        sort(candidates.begin(), candidates.end());
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
                if(i>start && candidates[i]==candidates[i-1]) continue;//TODO in case duplicate solution
                sol.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], res, sol, i+1);
                sol.pop_back();
            }
        }
    }
};
//public class CombinationSumUnique {
//
//    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
//        Arrays.sort(candidates);
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
//                dfs(candidates, target-candidates[i], res, sol, i+1);
//                sol.remove(sol.size()-1);
//            }
//        }
//    }
//
//}
