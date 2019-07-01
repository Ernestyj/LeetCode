/**
 * One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
Example 1:
Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:
Input: "1,#"
Output: false
Example 3:
Input: "9,#,#,1"
Output: false
 */
class Solution {
public:
    /**
     * 可以观察出如下两个规律：
     1. 数字的个数总是比#号少一个 2. 最后一个一定是#号
     不考虑最后一个#号，那么此时数字和#号的个数应该相同。初始化一个为0的计数器，遇到数字，计数器加1，遇到#号，计数器减1，那么到最后计数器应该还是0。
     通过这两个反例我们可以看出，如果根节点为空的话，后面不能再有节点，即不能有三个连续的#号出现。
     总结：正确的序列里，任何一个位置i，在[0, i]范围内的#号数都不大于数字的个数的
     */
    bool isValidSerialization(string preorder) {
        istringstream is(preorder);
        vector<string> v;
        string temp = "";
        int count = 0;
        while(getline(is, temp, ',')) v.push_back(temp);
        for (int i = 0; i < v.size() - 1; ++i) {
            if(v[i]=="#"){
                if(count==0) return false;
                --count;
            }else{
                ++count;
            }
        }
        return count==0 && v.back()=="#";   //检测计数器是否为0的同时还要看看最后一个字符是不是#号
    }
};

