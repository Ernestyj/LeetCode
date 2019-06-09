
/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 For example,
 If n = 4 and k = 2, a solution is:
 [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4] ]
 * Created by DCLab on 12/29/2015.
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sol;
        if(n == 0 || k == 0) return res;
        dfs(n, k, res, sol, 1);
        return res;
    }
    void dfs(int n, int k, vector<vector<int>>& res, vector<int>& sol, int start){
        if(k==0){
           res.push_back(sol);
        }else{
            for (int i = start; i <= n; ++i) {
                sol.push_back(i);
                dfs(n, k-1, res, sol, i+1);
                sol.pop_back();
            }
        }
    }
};
//public class Combinations {
//
//    public static void main(String[] args){
//        System.out.println("*****RESULT*****");
//        Combinations instance = new Combinations();
//        instance.combine(4, 2);
//        for (List<Integer> ints : instance.result){
//            for (Integer i : ints) System.out.print(i + " ");
//            System.out.println();
//        }
//    }
//
//
//    private List<List<Integer>> result = new ArrayList<>();
//    private List<Integer> temp = new ArrayList<>();
//    public List<List<Integer>> combine(int n, int k) {
//        if (n == 0 || k == 0) return result;
//        backTrack(n, k, 1);
//        return result;
//    }
//    private void backTrack(int n, int k, int start){
//        if (k == 0){
//            result.add(new ArrayList<>(temp));
//        }
//        for (int i=start; i<=n; i++){
//            temp.add(i);
//            backTrack(n, k - 1, i + 1);
//            temp.remove(temp.size()-1);
//        }
//    }
//
//}
