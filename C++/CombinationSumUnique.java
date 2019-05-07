package leetcode31_40;

import java.util.*;

/**Given a collection of candidate numbers (C) and a target number (T), find all unique
 combinations in C where the candidate numbers sums to T.
 Each number in C may only be used once in the combination.
 Note: All numbers (including target) will be positive integers.
 The solution set must not contain duplicate combinations.
 For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 A solution set is: [ [1, 7], [1, 2, 5], [2, 6], [1, 1, 6] ]
 * Created by DCLab on 11/23/2015.
 */
public class CombinationSumUnique {

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
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
                dfs(candidates, target-candidates[i], res, sol, i+1);
                sol.remove(sol.size()-1);
            }
        }
    }

}
