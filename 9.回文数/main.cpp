#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }

        char table[10];
        size_t top = 0;
        while (x != 0) {
            table[top++] = x % 10;
            x /= 10;
        }
        size_t left = 0;
        size_t right = top - 1;
        while (left < top) {
            if (table[left++] != table[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    while (true) {
        int num;
        std::cin >> num;
        std::cout << (solution.isPalindrome(num) ? "yes" : "no") << std::endl;
    }    
    return 0;
}
