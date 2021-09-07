#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string builder;
        
        _dfs(ret, builder, digits, 0);

        return ret;
    }

private:
    static void _dfs(vector<string>& out, string& builder, const string& digits, size_t index) {
        if (index == digits.length()) {
            if (builder.length() != 0) {
                out.emplace_back(builder);
            }
            return;
        }
        char c = digits[index];
        char first = (c - '2') * 3 + 'a';
        if (c > '7') {
            ++first;
        }
        size_t builder_index = builder.length();
        builder.push_back(first);
        _dfs(out, builder, digits, index + 1);
        builder[builder_index] = first + 1;
        _dfs(out, builder, digits, index + 1);
        builder[builder_index] = first + 2;
        _dfs(out, builder, digits, index + 1);
        if (c == '9' || c == '7') {
            builder[builder_index] = first + 3;
            _dfs(out, builder, digits, index + 1);
        }
        builder.pop_back();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    while (true) {
        string digits;
        std::getline(std::cin, digits);
        auto res = solution.letterCombinations(digits);
        std::copy(res.begin(), res.end(), std::ostream_iterator<string>(std::cout, ", "));
        std::cout << std::endl;
    }
    
    return 0;
}
