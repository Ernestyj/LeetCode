package leetcode111_120;

import java.util.ArrayList;
import java.util.List;

/**Given numRows, generate the first numRows of Pascal's triangle.
 For example, given numRows = 5,
 Return
 [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]
 * Created by eugene on 16/2/7.
 */
public class PascalTriangle {

    /**
     * 时间复杂度O(1+2+3+...+n)=O(n^2)，空间上只需要二维数组来存储结果;
     因为是求解每一行结果，所以空间上没有更优的办法.
     * @param numRows
     * @return
     */
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows==0) return result;
        List<Integer> pre = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        pre.add(1);
        result.add(pre);
        int row = 1;
        while (row < numRows){
            cur.add(1);
            for (int i=0; i<pre.size()-1; i++){
                cur.add(pre.get(i) + pre.get(i+1));
            }
            cur.add(1);
            result.add(cur);
            pre = cur;
            cur = new ArrayList<>();
            row++;
        }
        return result;
    }

}
