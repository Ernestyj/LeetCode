package leetcode41_50;

import com.sun.deploy.util.ArrayUtil;

import javax.xml.stream.events.Characters;
import java.util.*;

/**
 * Given an array of strings, group anagrams together.
 For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Return:
 [
 ["ate", "eat","tea"],
 ["nat","tan"],
 ["bat"]
 ]
 Note:
 For the return value, each inner list's elements must follow the lexicographic order.
 All inputs will be in lower-case.
 * Created by DCLab on 12/2/2015.
 */
public class GroupAnagrams {

    public static void main(String[] args) {
        String[] strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
        System.out.println("*****RESULT*****");
        List<List<String>> result = new GroupAnagrams().groupAnagrams(strs);
        for (List<String> list : result){
            for (String s : list){
                System.out.print(s + " ");
            }
            System.out.println();
        }
    }


    //易位构词的排序结果是一样的
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs == null || strs.length == 0) return new ArrayList<>();
        Arrays.sort(strs);
        HashMap<String, List<String>> books = new HashMap<>();
        String s;
        char[] chars;
        List<String> temp;
        for (int i = 0; i < strs.length; i++){
            chars = strs[i].toCharArray();
            Arrays.sort(chars);
            s = String.valueOf(chars);
            if (books.containsKey(s)){
                books.get(s).add(strs[i]);
            } else {
                temp = new ArrayList<>();
                temp.add(strs[i]);
                books.put(s, temp);
            }
        }
        return new ArrayList<>(books.values());
    }


    //TODO 超时
    public List<List<String>> groupAnagrams1(String[] strs) {
        Arrays.sort(strs);
        List<String> temp;
        HashMap<HashMap<Character, Integer>, List<String>> books = new HashMap<>();
        HashMap<Character, Integer> book;
        for (int i = 0; i < strs.length; i++){
            book = new HashMap<>();
            //获取小字典
            for (char c : strs[i].toCharArray()){
                if (book.containsKey(c)) book.put(c, book.get(c) + 1);
                else book.put(c, 1);
            }
            //大字典中找小字典
            if (books.containsKey(book)) {
                temp = books.get(book);
                temp.add(strs[i]);
            } else {
                temp = new ArrayList<>();
                temp.add(strs[i]);
                books.put(book, temp);
            }
        }
        return new ArrayList<>(books.values());
    }
}
