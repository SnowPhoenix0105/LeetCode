#include <string>
#include <iostream>

using std::string;

/*
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
public:
    int romanToInt(char c) {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

    int romanToInt(string s) {
        int ret = 0;
        int last_num = 1000;
        for (char c : s) {
            int current_num = romanToInt(c);
            if (current_num > last_num) {
                ret -= (last_num << 1);
            }
            ret += current_num;
            last_num = current_num;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    while (true) {
        string s;
        std::getline(std::cin, s);
        std::cout << solution.romanToInt(s) << std::endl;
    }
    return 0;
}
