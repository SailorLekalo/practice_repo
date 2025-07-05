#include <vector>

class Solution {
public:
    std::vector<int> findClosestElements(std::pmr::vector<int>& arr, int k, int x) {
        std::vector<int> result;
        result.reserve(k);

        int l_p = 0;
        // last valid window start
        int r_p = arr.size() - k;

        while (l_p < r_p) {
            int m_p = (r_p + l_p) / 2;
            // search left if middle point elem gives better difference
            if (x - arr[m_p] <= arr[m_p + k] - x) {
                // left elem is not farther than after-middle-window elem
                r_p = m_p;
            } else {
                l_p = m_p + 1;
            }
        }

        for (int i = 0; i < k; ++i) {
            result.push_back(arr[l_p + i]);
        }

        return result;
    }
};

/*

lm
-1,0,1,2,3,4,5,6    4,1
   r

     l
-1,0,2,5,18         3, 11
     r

            l
1,1,2,2,2,2,2,3,3   3, 3
            r

*/

// Runtime: O(log(n(-k))+k)
// Memory: O(k)
