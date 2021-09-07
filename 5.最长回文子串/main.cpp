#include <string>
#include <iostream>

using std::string;

void dump(bool* table, size_t count, size_t x, size_t y) {
    bool *ptr = table;
    std::cout << '\n';
    for (size_t i = 0; i != count; ++i) {
        for (size_t j = 0; j != count; ++j) {
            if (i == x && j == y) {
                std::cout << ((*ptr++) ? "T " : "F ");
            }
            else {
                std::cout << ((*ptr++) ? "t " : "f ");
            }
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

void dump(bool* table, size_t count) {
    bool *ptr = table;
    std::cout << '\n';
    for (size_t i = 0; i != count; ++i) {
        for (size_t j = 0; j != count; ++j) {
            std::cout << ((*ptr++) ? "t " : "f ");
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

class Solution {
public:
    string longestPalindrome(string s) {
        count = s.length();
        if (count == 1) {
            return s;
        }
        if (count == 2) {
            if (s[0] == s[1]) {
                return s;
            }
            return s.substr(0, 1);
        }

        size_t size = count * count;
        table = new bool[size];
        init(size, s);
        // dump(table, count);
        walk(s);
        // dump(table, count);
        // std::cout << max_beg << ' ' << max_length << '\n';

        delete[] table;

        return s.substr(max_beg, max_length);
    }

private:
    size_t count;
    bool *table;
    size_t max_beg;
    size_t max_length;

    void init(size_t size, const string& s) {
        max_beg = 0;
        max_length = 1;
        bool *ptr = table;
        for (size_t i = 0; i != count - 1; ++i) {
            *ptr++ = true;
            bool tmp = (s[i] == s[i+1]);
            *ptr = tmp;
            if (tmp) {
                max_beg = i;
                max_length = 2;
            }
            ptr += count;
        }
        *ptr = true;
    }

    void walk(const string&s) {
        for (size_t delta = 2; delta != count; ++delta) {
            size_t length = delta + 1;
            size_t beg_upbound = count - delta;
            bool *ptr = table + delta;
            for (size_t beg = 0; beg != beg_upbound; ++beg) {
                size_t end = beg + delta;
                if (s[beg] != s[end]) {
                    *ptr = false;
                }
                else if (!ptr[count - 1]) {
                    *ptr = false;
                }
                else {
                    *ptr = true;
                    if (length > max_length) {
                        max_beg = beg;
                        max_length = length;
                    }
                }
                // dump(table, count, beg, end);
                ptr += count + 1;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s;
    std::getline(std::cin, s);
    string res = solution.longestPalindrome(s);
    std::cout << res.length() << '\n' << res << std::endl;
    return 0;
}
