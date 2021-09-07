#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

void printResult(const vector<vector<int>>& res) {
    std::cout << "res:_________\n";
    for (const auto& tuple : res) {
        std::cout << '[' << tuple[0] << tuple[1] << tuple[2] << ']' << '\n';
    }
        std::cout << "----------" << std::endl;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        size_t num_size = nums.size();
        if (num_size < 3) {
            return ret;
        }

        std::sort(nums.begin(), nums.end());

        int last_target = -1 - nums[0];
        for (size_t i = 0; i != num_size; ++i) {
            int target = -nums[i];
            if (last_target == target) {
                continue;
            }
            last_target = target;
            size_t head = i + 1;
            size_t tail = num_size - 1;
            while (head < tail) {
                int nh = nums[head];
                int nt = nums[tail];
                int sum = nh + nt;
                if (sum == target) {
                    ret.emplace_back(vector<int>({-target, nh, nt}));
                    while (head < tail) {
                        ++head;
                        if (nh != nums[head]) break;
                    };
                    while (head < tail) {
                        --tail;
                        if (nt != nums[tail]) break;
                    }
                }
                else if (sum < target) {
                    while (head < tail) {
                        ++head;
                        if (nh != nums[head]) break;
                    };
                }
                else {
                    while (head < tail) {
                        --tail;
                        if (nt != nums[tail]) break;
                    }
                }
                // printResult(ret);
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    while (true) {
        char op = ',';
        int num;
        vector<int> nums;
        while (op == ',') {
            std::cin >> num >> op;
            std::cout << op;
            nums.push_back(num);
        }
        std::cout << "start" << std::endl;
        auto ret = solution.threeSum(nums);
        printResult(ret);
    }
    return 0;
}
