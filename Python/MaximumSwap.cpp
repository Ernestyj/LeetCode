//
// Created by Eugene on 2019-08-01.
//

class Solution {
public:
    /**
     * @param num: a non-negative intege
     * @return: the maximum valued number
     */
    int maximumSwap(int num) {
        string str = to_string(num);
        int res = num;
        for (int i = 0; i < str.size(); ++i) {
            for (int j = i + 1; j < str.size(); ++j) {
                swap(str[i], str[j]);
                res = max(res, stoi(str));
                swap(str[i], str[j]);
            }
        }
        return res;
    }

};