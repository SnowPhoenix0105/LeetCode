#include <string>
#include <iostream>

using std::string;


class Solution {
public:
    bool isValid(string s) {
        size_t stack_length = s.length() / 2 + 1;

        // it's better to use std::unique_ptr, 
        // but I don't know is <memory> included 
        // in testing env
        char* stack = new char[stack_length];
        size_t top = 0;
        char target_left = 0;
        for (char c : s) {
            switch (c) {
                case '[':
                case '{':
                case '(':
                    stack[top++] = c;
                    if (top >= stack_length) {
                        delete[] stack;
                        return false;
                    }
                    break;
                case ']':
                case '}':
                    target_left = 1;
                case ')':
                    target_left = c - 1 - target_left;
                    if (top == 0) {
                        delete[] stack;
                        return false;
                    }
                    if (stack[--top] != target_left) {
                        delete[] stack;
                        return false;
                    }
                    target_left = 0;
                default:
                    break;
            }
        }
        delete[] stack;
        return top == 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution solution;
    while (true) {
        string s;
        std::getline(std::cin, s);
        std::cout << (solution.isValid(s) ? "yes" : "no") << std::endl;
    }
    return 0;
}
