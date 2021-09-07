#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        size_t min_length = strs[0].length();
        for (const auto& str : strs) {
            if (str.length() < min_length) {
                min_length = str.length();
            }
        }
        string ret;
        for (size_t i = 0; i != min_length; ++i) {
            char c = strs[0][i];
            for (const auto& str : strs) {
                if (str[i] != c) {
                    return ret;
                }
            }
            ret.push_back(c);
        }
        return ret;
    }
};
