#include <unordered_map>

/**Given a roman numeral, convert it to an integer.
 Input is guaranteed to be within the range from 1 to 3999.
 * Created by eugene on 16/6/1.
 */
class Solution {
public:
    int romanToInt(string s) {
        if(s.size()==0) return 0;
        int len = s.size();
        unordered_map<char, int> map = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        };
        int result = map[s[len-1]];
        int pivot = result;
        for (int i = len-2; i>=0; --i) {
            int cur = map[s[i]];
            if (cur>=pivot) result += cur;
            else result -= cur;

            pivot = cur;
        }
        return result;
    }
};
