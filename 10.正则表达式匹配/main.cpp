#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

void dump(const string& s, size_t current_index, const vector<char>& table, const vector<size_t>& current, const vector<size_t>& next) {
    std::cout << "_________________________________________\n" << s << '\n';
    for (size_t i = 0; i != current_index; ++i) {
        std::cout << ' ';
    }
    std::cout << '^' << '\n';

    for (char c : table) {
        std::cout << c;
    }
    std::cout << '\n';

    size_t index = 0;
    for (size_t i = 0; i <= table.size(); ++i) {
        if (index < current.size() && current[index] == i) {
            std::cout << '*';
            ++index;
        }
        else {
            std::cout << ' ';
        }
    }
    std::cout << '\n';

    index = 0;
    for (size_t i = 0; i <= table.size(); ++i) {
        if (index < next.size() && next[index] == i) {
            std::cout << '*';
            ++index;
        }
        else {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<char> table;
        vector<bool> loop;

        init(p, table, loop);
        return match(s, table, loop);
    }

    void init(const string& p, vector<char>& table, vector<bool>& loop) {
        for (char c : p) {
            if (c == '*') {
                loop[loop.size() - 1] = true;
                continue;
            }
            table.push_back(c);
            loop.push_back(false);
        }
    }

    bool match(const string& s, const vector<char>& table, const vector<bool>& loop) {
        size_t current_index = 1;
        vector<size_t> status[2];
        size_t table_size = table.size();

        {
            size_t sta = 0;
            do {
                status[current_index].push_back(sta);
            } while (sta < table_size - 1 && loop[sta++]);
        }
        for (size_t i = 0; i != s.length(); ++i) {
            char c = s[i];
            const vector<size_t>& current = status[current_index];
            vector<size_t>& next = status[1 - current_index];
            next.clear();
            for (size_t sta : current) {
                if (sta >= table_size) {
                    continue;
                }
                if (next.size() != 0 && next.at(next.size() - 1) > sta) {
                    continue;
                }
                char require = table[sta];
                if (require == '.' || require == c) {
                    if (loop[sta]) {
                        if (next.size() == 0 || next.at(next.size() - 1) < sta) {
                            next.push_back(sta);
                        }
                    }
                    size_t next_sta = sta + 1;
                    do {
                        next.push_back(next_sta);
                    }
                    while (next_sta < table_size && loop[next_sta++]);
                }
            }

            dump(s, i, table, current, next);

            current_index = 1 - current_index;
        }

        {
            const vector<size_t>& current = status[current_index];
            return current.size() != 0 && current.at(current.size() - 1) == table_size;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    while (true) {
        string s;
        string p;
        std::getline(std::cin, s);
        std::getline(std::cin, p);
        std::cout << (solution.isMatch(s, p) ? "yes" : "no") << std::endl;
    }
    return 0;
}

