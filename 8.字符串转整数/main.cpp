#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    bool inline is_digit(char c) {
        return '0' <= c && c <= '9';
    }

    int myAtoi(string s) {
        bool neg = false;
        const char *ptr = s.c_str();

        while ((*ptr) == ' ') ptr++;

        char c = *ptr;
        if (c == '+') {
            neg = false;
            c = *++ptr;
            
        }
        else if (c == '-') {
            neg = true;
            c = *++ptr;
        }
        if (!is_digit(c)){
            return 0;
        }
        
        // now ptr point to the first number

        while ((*ptr) == '0') ptr++;

        c = *ptr;
        if (!is_digit(c)) {
            return 0;
        }

        int ret = c - '0';
        for (size_t  i = 1; i != 9; ++i) {
            char c = ptr[i];
            if (is_digit(c)) {
                ret *= 10;
                ret += (c - '0');
            }
            else {
                if (neg) {
                    return -ret;
                }
                return ret;
            }
        }
        char last = ptr[9];
        if (is_digit(last)) {
            int safe_line = 0x7fffffff / 10;
            if (is_digit(ptr[10]) || ret > safe_line) {
                if (neg) {
                    return -2147483648;
                }
                return 0x7fffffff;
            }
            if (ret == safe_line) {
                if (last >= '8') {
                    if (neg) {
                        return -2147483648;
                    }
                    return 0x7fffffff;
                }
            }
            ret *= 10;
            ret += last - '0';
        }
        if (neg) {
            return -ret;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    Solution solution;
    while (true) {
        std::getline(std::cin, s);
        std::cout << solution.myAtoi(s) << std::endl;
    }
    return 0;
}
