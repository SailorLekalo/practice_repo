class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 5000;
        int l_p = 0;
        int r_p = nums.size() - 1;

        while (l_p < r_p) {
            // on zero rotation in current subarray, finish
            if (nums[l_p] < nums[r_p]) {
                min = std::min(min, nums[l_p]);
                break;
            }

            int m_p = (r_p + l_p) / 2;
            // go to non-sorted subarray
            if (nums[l_p] <= nums[m_p]) {
                l_p = m_p + 1;
            } else {
                r_p = m_p;
            }
        }

        return std::min(min, nums[l_p]);
    }
};

/*

         m  l
14,15,16,17,0,1,12,13
                   r

*/

// Runtime: O(log n)
// Memory: O(1)
