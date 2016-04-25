package leetcode51_60;

import java.util.ArrayList;
import java.util.List;

/**
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 1."123" 2."132" 3."213" 4."231" 5."312" 6."321"
 Given n and k, return the kth permutation sequence.
 Note: Given n will be between 1 and 9 inclusive.

 * Created by DCLab on 12/13/2015.
 */
public class PermutationSequence {

    public static void main(String[] args) {
        String result = new PermutationSequence().getPermutation(9, 362880);
        System.out.println(result);
    }

    /** 发现数学规律进行解题：
     * 1. 以某一数字开头的排列有(n-1)!个，先计算(n-1)!；k=k-1将k转换为从0开始（原来k从1开始）；
     2. 第一位数字是“原字符串”位置k/(n-1)!处的字符；更新k=k%(n-1)!；
     3. 第二位数字是“原字符串”位置k/(n-2)!处的字符；更新k=k%(n-2)!；
     4. 不断重复2、3，直至第n位数字。（注意：每确定一位数字，“原字符串”应移除该数字）
     时间复杂度：O(n^2)；空间复杂度：O(n)；
     参考：http://blog.csdn.net/linhuanmars/article/details/22028697
     * @param n
     * @param k
     * @return
     */
    public String getPermutation(int n, int k) {
        StringBuilder sb = new StringBuilder();
        //生成原字符串
        List<Integer> origin = new ArrayList<>();
        for(int i = 1; i <= n; i++) origin.add(i);
        //计算(n-1)!
        int factorial = 1;
        for (int i = 1; i < n; i++) factorial *= i;
        //k转换为从0开始
        k = k - 1;
        //计算Kth全排列串中第i位(0<i<n)数字
        for (int i = 0; i < n; i++) {
            int index = k / factorial;  //得到第i位数字字符
            k = k % factorial;  //更新k
            sb.append(origin.get(index));
            origin.remove(index); //每确定一位数字，“原字符串”应移除该数字
            if (i < n - 1) {    //更新factorial
                factorial = factorial / (n - 1 - i);
            }
        }
        return sb.toString();
    }


    //TODO 使用Next Permutation会大数据超时


    private List<String> strings = new ArrayList<>();
    /**TODO 此解法大数据超时，超时用例n=9, k=54494
     * 题目要求全排列有序，而Permutations这题中用回溯法得到的全排列并非有序。
     * 另一种思路：递归法。
     * 参考：http://www.ericleschinski.com/c/java_permutations_recursion/
     * @param n
     * @param k
     * @return
     */
    public String getPermutation1(int n, int k) {
        StringBuilder builder = new StringBuilder();
        for (int i = 1; i <= n; i++) builder.append(i);
        String s = builder.toString();
        permutation("", s);
        return strings.get(k - 1);
    }
    private void permutation(String prefix, String str) {
        int len = str.length();
        if (len == 0) strings.add(prefix);
        else {
            for (int i = 0; i < len; i++)
                permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, len));
        }
    }

}
