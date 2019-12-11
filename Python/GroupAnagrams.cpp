

/**
 * Given an array of strings, group anagrams together.
 For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Return: [ ["ate", "eat","tea"],
 ["nat","tan"],
 ["bat"] ]
 Note: For the return value, each inner list's elements must follow the lexicographic order.
 All inputs will be in lower-case.
 * Created by DCLab on 12/2/2015.
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;//也可以先对strs排序
        vector<vector<string>> res;
        for(auto s: strs){
            string sortS = s;
            sort(sortS.begin(), sortS.end());
            m[sortS].push_back(s);
        }
        for(auto item: m){
            res.push_back(item.second);
        }
        return res;
    }
};
//public class GroupAnagrams {
//
//    //易位构词的排序结果是一样的
//    public List<List<String>> groupAnagrams(String[] strs) {
//        Arrays.sort(strs);
//        HashMap<String, List<String>> map = new HashMap<>();
//        for(String str: strs){
//            char[] chars = str.toCharArray();
//            Arrays.sort(chars);
//            String s = String.valueOf(chars);
//            if(!map.containsKey(s)) map.put(s, new LinkedList<>());
//            map.get(s).add(str);
//        }
//        return new LinkedList<>(map.values());
//    }
//
//}
