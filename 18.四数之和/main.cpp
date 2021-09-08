#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void printResult(const vector<vector<int>>& res) {
    std::cout << "res:_________\n";
    for (const auto& tuple : res) {
        std::cout << '[' << tuple[0] << ',' << tuple[1] << ',' << tuple[2] << ',' << tuple[3] << ']' << '\n';
    }
    std::cout << "----------" << std::endl;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        size_t nums_size = nums.size();
        vector<vector<int>> ret;
        if (nums_size < 4) {
            return ret;
        }
        
        std::sort(nums.begin(), nums.end());


        int ni = nums[0] - 1;
        for (size_t i = 0; i != nums_size - 3; ++i) {
            if (ni == nums[i]) continue;
            ni = nums[i];
            int nj = ni - 1;
            for (size_t j = i + 1; j != nums_size - 2; ++j) {
                if (nj == nums[j]) continue;
                nj = nums[j];
                size_t head = j + 1;
                size_t tail = nums_size - 1;
                while (head < tail) {
                    int nh = nums[head];
                    int nt = nums[tail];
                    long long distance = ((long long) target) - ni - nj - nh - nt;
                    if (distance == 0) {
                        ret.emplace_back(std::initializer_list<int>({ni, nj, nh, nt}));
                        while (head < tail && nh == nums[++head]);
                        while (head < tail && nt == nums[--tail]);
                    }
                    else if (distance < 0) {
                        while (head < tail && nt == nums[--tail]);
                    }
                    else {
                        while (head < tail && nh == nums[++head]);
                    }
                }
            }
        }


        return ret;
    }
};


int main(int argc, char const *argv[])
{
    Solution solution;
    while (true) {
        vector<int> nums;
        while (true) {
            int num;
            char op;
            std::cin >> num >> op;
            nums.push_back(num);
            if (op == '.') break;
        }
        int target;
        std::cin >> target;
        auto res = solution.fourSum(nums, target);
        printResult(res);
    }
    return 0;
}
