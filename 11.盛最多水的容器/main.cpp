#include <vector>

using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t head = 0;
        size_t tail = height.size() - 1;

        int max_v = 0;
        while (head < tail) {
            int hh = height[head];
            int ht = height[tail];
            int v = std::min(hh, ht) * (tail - head);
            if (v > max_v) {
                max_v = v;
            }
            if (hh >= ht) {
                --tail;
            }
            if (hh <= ht) {
                ++head;
            }
        }

        return max_v;
    }
};