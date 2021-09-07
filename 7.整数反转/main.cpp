#include <iostream>

class Solution {
public:
    int reverse(int x) {
        if (-10 < x && x < 10) {
            return x;
        }
        if (x < 0 && x + 0x7fffffff == -1) {
            return 0;
        }
        bool neg = (x < 0);
        if (neg) {
            x = -x;
        }

        size_t top = 0;
        char table[10];

        while (x != 0){
            table[top++] = x % 10;
            x /= 10;
        }
        if (top == 10) {
            if (table[0] > 2) {
                return 0;
            }
        }
        int ret = table[0];
        size_t end = top;
        if (top == 10) {
            end = 9;
        }
        for (size_t i = 1; i != end; ++i) {
            ret *= 10;
            ret += table[i];
        }
        if (top == 10) {
            if (ret > (0x7fffffff / 10)) {
                return 0;
            }
            ret *= 10;
            ret += table[9];
        }
        if (neg) {
            return -ret;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    while (true) {
        int x;
        std::cin >> x;
        std::cout << solution.reverse(x) << std::endl;
    }

    return 0;
}
