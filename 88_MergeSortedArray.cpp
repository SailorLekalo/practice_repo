#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // read and write from ends
        int p1 = m - 1;
        int p2 = n - 1;
        int write = m + n - 1;

        while (p1 >= 0 && p2 >= 0) {
            // write at the end the greater num from two arrays
            if (nums1[p1] > nums2[p2]) {
                nums1[write] = nums1[p1];
                --p1;
            } else {
                nums1[write] = nums2[p2];
                --p2;
            }
            --write;
        }

        // nums2 may have not been entirely copied yet
        while (p2 >= 0) {
            nums1[write] = nums2[p2];
            --p2;
            --write;
        }
    }
};

// Runtime: O(m(+n))
// Memory: O(1)
