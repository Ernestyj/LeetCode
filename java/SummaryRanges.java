package leetcode221_230;

import java.util.ArrayList;
import java.util.List;

/**Given a sorted integer array without duplicates, return the summary of its ranges.
 For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * Created by eugene on 16/4/23.
 */
public class SummaryRanges {

    public List<String> summaryRanges(int[] nums) {
        List<String> list = new ArrayList();
        for(int i=0; i<nums.length; i++){
            int n = nums[i];
            while(i+1<nums.length && nums[i+1]-nums[i]==1) i++;
            if(n!=nums[i]){
                list.add(n+"->"+nums[i]);
            }else{
                list.add(n+"");
            }
        }
        return list;
    }

    public List<String> summaryRanges1(int[] nums) {
        List<String> result = new ArrayList<>();
        if (nums.length==0) return result;
        int start = nums[0];
        int count = 1;
        StringBuilder builder = new StringBuilder();
        builder.append(start);
        for (int i=1; i<nums.length; i++){
            if (nums[i]-nums[i-1]==1){
                count++;
            } else {
                if (count==1) {
                    result.add(builder.toString());
                } else {
                    result.add(builder.append("->"+nums[i-1]).toString());
                }
                builder = new StringBuilder(""+nums[i]);
                count = 1;
            }
        }
        if (count!=1) result.add(builder.append("->"+nums[nums.length-1]).toString());
        else result.add(builder.toString());
        return result;
    }

}
