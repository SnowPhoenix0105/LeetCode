#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int min_distance = target - closest;
        if (min_distance < 0) {
            min_distance = -min_distance;
        }
        else if (min_distance == 0) {
            return target;
        }
        size_t num_size = nums.size();

        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i != num_size; ++i) {
            int remain = target - nums[i];
            size_t head = i + 1;
            size_t tail = num_size - 1;
            while (head < tail) {
                int nh = nums[head];
                int nt = nums[tail];
                int distance = remain - nh - nt;
                if (distance == 0) {
                    return target;
                }
                int abs_dis;
                if (distance > 0) {
                    abs_dis = distance;
                    while (head < tail) {
                        ++head;
                        if (nh != nums[head]) break;
                    };
                }
                else {
                    abs_dis = -distance;
                    while (head < tail) {
                        --tail;
                        if (nt != nums[tail]) break;
                    }
                }
                if (abs_dis < min_distance) {
                    closest = target - distance;
                    min_distance = abs_dis;
                }
                // std::cout << '[' << i << ',' << head << ',' << tail << ']' << closest << '\n';
            }
        }

        return closest;
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
            nums.push_back(num);
        }
        int target;
        std::cin >> target;
        std::cout << solution.threeSumClosest(nums, target) << std::endl;
    }
    return 0;
}
