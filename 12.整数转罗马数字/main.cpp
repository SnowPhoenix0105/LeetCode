#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        ret.append(num / 1000, 'M');
        num %= 1000;
        generate(ret, num / 100, 'M', 'D', 'C');
        num %= 100;
        generate(ret, num / 10, 'C', 'L', 'X');
        num %= 10;
        generate(ret, num, 'X', 'V', 'I');
        return ret;
    }

    /*times in [0, 10)*/
    void generate(string& out, int times, char ten, char five, char one) {
        if (times > 5) {
            if (times == 9) {
                out.push_back(one);
                out.push_back(ten);
                return;
            }
            times -= 5;
            out.push_back(five);
        }
        switch (times)
        {
        case 3:
            out.push_back(one);
        case 2:
            out.push_back(one);
        case 1:
            out.push_back(one);
            break;
        case 4:
            out.push_back(one);
        case 5:
            out.push_back(five);
        default: // 0
            break;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    while (true) {
        int num;
        std::cin >> num;
        std::cout << solution.intToRoman(num) << std::endl;
    }
    return 0;
}
