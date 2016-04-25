package leetcode211_220;

import java.util.*;

/**Find all possible combinations of k numbers that add up to a number n, given that only numbers
 from 1 to 9 can be used and each combination should be a unique set of numbers.
 Ensure that numbers within the set are sorted in ascending order.
 Example 1:
 Input: k = 3, n = 7
 Output: [[1,2,4]]
 Example 2:
 Input: k = 3, n = 9
 Output: [[1,2,6], [1,3,5], [2,3,4]]
 * Created by eugene on 16/4/12.
 */
public class CombinationSumIII {

    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<Integer> list = new ArrayList<>();
        dfs(k, n, list, 1);
        return res;
    }
    private void dfs(int k, int sum, List<Integer> list, int start){
        if(sum==0 && list.size()==k){
            res.add(new ArrayList<>(list));
        }
        for(int i=start; i<=9; i++){
            if(sum-i<0) break;
            if(list.size()>=k) break;
            list.add(i);
            dfs(k, sum-i, list, i+1);   //TODO 注意i+1不要写成start+1
            list.remove(list.size()-1);
        }
    }

}
