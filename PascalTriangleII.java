package leetcode111_120;

import java.util.ArrayList;
import java.util.List;

/**Given an index k, return the kth row of the Pascal's triangle.
 k=5时Pascal三角如下:
 [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]
 For example, given k = 3, Return [1,3,3,1].
 Note: Could you optimize your algorithm to use only O(k) extra space?
 * Created by eugene on 16/2/7.
 */
public class PascalTriangleII {

    /**
     * 与Pascal's Triangle类似,但是空间可以压缩为O(k).注意in-place更新值时要逆序(观察Pascal三角的特点)
     * @param rowIndex
     * @return
     */
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>();
        if (rowIndex<0) return result;
        result.add(1);
        for (int row=1; row<rowIndex+1; row++){
            for (int j=result.size()-1; j>0; j--){    //TODO 注意一定要倒序遍历,因为顺序会覆盖值
                result.set(j, result.get(j-1) + result.get(j));
            }
            result.add(1);
        }
        return result;
    }

}
