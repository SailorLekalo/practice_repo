#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;

        // max heights seen so far from left/right sides
        int l_max = 0;
        int r_max = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                // there is higher height on right side
                // water level is determined by left max height only
                if (height[l] >= l_max) {
                    l_max = height[l];
                } else {
                    res += l_max - height[l];
                }
                ++l;
            } else {
                // water level is determined by right max height only
                if (height[r] >= r_max) {
                    r_max = height[r];
                } else {
                    res += r_max - height[r];
                }
                --r;
            }
        }

        return res;
    }
};

// Runtime: O(N)
// Memory: O(1)
