
/**Given a list of non negative integers, arrange them such that they form the largest number.
 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 Note: The result may be very large, so you need to return a string instead of an integer.
 * Created by eugene on 16/3/23.
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        if(!nums.size()) return "";
        sort(nums.begin(), nums.end(), [](int a, int b){ return to_string(a)+to_string(b)>to_string(b)+to_string(a); });//降序
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res[0]=='0'? "0":res;
    }
};
//public class LargestNumber {
//
//    //简洁写法. 关键:拼接待比较的两个数o1与o2，s1=o1+o2，s2=o2+o1，从s1、s2的最高位开始比较
//    public  String largestNumber(int[] nums) {
//        if(nums==null || nums.length==0) return "";
//        String[] numS = new String[nums.length];
//        for(int i=0; i<nums.length; i++)
//            numS[i] = nums[i]+"";
//        Comparator<String> comp = new Comparator<String>(){ //升序
//            @Override
//            public int compare(String str1, String str2){
//                String s1 = str1+str2;
//                String s2 = str2+str1;
//                return s1.compareTo(s2);
//            }
//        };
//        Arrays.sort(numS, comp);
//        if(numS[numS.length-1].charAt(0)=='0')
//            return "0";
//        StringBuilder sb = new StringBuilder();
//        for(String s: numS)
//            sb.insert(0, s);    //降序
//        return sb.toString();
//    }
//
//    //拼接待比较的两个数o1与o2，s1=o1+o2，s2=o2+o1，从s1、s2的最高位开始比较。
//    public String largestNumber1(int[] nums) {
//        if (nums.length==1) return String.valueOf(nums[0]);
//        List<String> list = new ArrayList<>();
//        for (int i : nums) list.add(String.valueOf(i));
//        list.sort(new Comparator<String>() {    //升序
//            @Override
//            public int compare(String o1, String o2) {
//                String s1 = o1+o2;
//                String s2 = o2+o1;
//                return s1.compareTo(s2);
//            }
//        });
//        StringBuilder builder = new StringBuilder();
//        for (int i=list.size()-1; i>=0; i--) builder.append(list.get(i));   //降序
//        String result = builder.toString();
//        if (result.charAt(0)=='0') return "0";  //用例[0, 0]
//        return result;
//    }
//
//}
