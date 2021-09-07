#include <string>
#include <iostream>

using std::string;


    

int main(int argc, char const *argv[])
{
    string s;
    int num;
    std::getline(std::cin, s);
    std::cin >> num;
    Solution solution;
    std::cout << solution.convert(s, num) << std::endl;

    return 0;
}

