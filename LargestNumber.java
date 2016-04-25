package leetcode171_180;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**Given a list of non negative integers, arrange them such that they form the largest number.
 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 Note: The result may be very large, so you need to return a string instead of an integer.
 * Created by eugene on 16/3/23.
 */
public class LargestNumber {

    //拼接待比较的两个数o1与o2，s1=o1+o2，s2=o2+o1，从s1、s2的最高位开始比较。
    public String largestNumber(int[] nums) {
        if (nums.length==1) return String.valueOf(nums[0]);
        List<String> list = new ArrayList<>();
        for (int i : nums) list.add(String.valueOf(i));
        list.sort(new Comparator<String>() {    //升序
            @Override
            public int compare(String o1, String o2) {
                char[] chars1 = (o1+o2).toCharArray();
                char[] chars2 = (o2+o1).toCharArray();
                int len = chars1.length;
                for (int i=0; i<len; i++){
                    if (chars1[i]>chars2[i]) return 1;
                    else if (chars1[i]<chars2[i]) return -1;
                }
                return 0;
            }
        });
        StringBuilder builder = new StringBuilder();
        for (int i=list.size()-1; i>=0; i--) builder.append(list.get(i));   //降序
        String result = builder.toString();
        if (result.charAt(0)=='0') return "0";  //用例[0, 0]
        return result;
    }

}
