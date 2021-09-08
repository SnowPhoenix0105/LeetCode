#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string builder;
        builder.reserve(2 * n);
        dfs(ret, builder, n, 0);
        return ret;
    }
private:
    void dfs(vector<string>& out, string builder, int left, int right) {
        if (left > 0) {
            builder.push_back('(');
            dfs(out, builder, left - 1, right + 1);
            builder.pop_back();
        }
        if (right > 0) {
            builder.push_back(')');
            dfs(out, builder, left, right - 1);
            builder.pop_back();
        }
        else if (left == 0) {
            out.emplace_back(builder);
        }
    }
};

