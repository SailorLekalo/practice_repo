class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l_p = 0;
        int r_p = nums.size() - 1;

        while (l_p < r_p) {
            // m_p points at the last elem of left subarray
            int m_p = l_p + (r_p - l_p) / 2;
            if (nums[m_p] == target) {
                return m_p;
            }

            if (nums[l_p] <= nums[m_p]) {
                // target is not within the sorted subarray
                if (nums[l_p] > target || nums[m_p] < target) {
                    // since left is sorted, forget it and move to the right subarray
                    l_p = m_p + 1;
                } else {
                    r_p = m_p;
                }
            } else {
                // same logic when right subarray is the sorted one
                if (nums[m_p + 1] > target || nums[r_p] < target) {
                    r_p = m_p;
                } else {
                    l_p = m_p + 1;
                }
            }
        }

        // the last number left can still be the target
        if (nums[l_p] == target) {
            return l_p;
        }
        return - 1;
    }
};

/*
         m
       l   r
[4,5,6,7,0,1]


*/

// Runtime: O(log n)
// Memory: O(1)
