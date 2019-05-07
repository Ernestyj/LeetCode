package leetcode31_40;

import java.util.*;

/**Given a set of candidate numbers (C) and a target number (T), find all unique combinations
 in C where the candidate numbers sums to T.
 The same repeated number may be chosen from C unlimited number of times.
 Note: All numbers (including target) will be positive integers.
 The solution set must not contain duplicate combinations.
 For example, given candidate set [2, 3, 6, 7] and target 7,
 A solution set is:
 [ [7], [2, 2, 3] ]
 * Created by DCLab on 11/22/2015.
 */
public class CombinationSum {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Set<List<Integer>> res = new HashSet<>();
        dfs(candidates, target, res, new LinkedList<>(), 0);
        return new LinkedList<>(res);
    }
    private void dfs(int[] candidates, int target, Set<List<Integer>> res, List<Integer> sol, int start){
        if(target==0){
            res.add(new LinkedList<>(sol));
            return;
        }
        for(int i=start; i<candidates.length; i++){
            if(target-candidates[i]>=0){
                sol.add(candidates[i]);
                dfs(candidates, target-candidates[i], res, sol, i);//TODO 这里是i
                sol.remove(sol.size()-1);
            }
        }
    }

}
