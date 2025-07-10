#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList) {
        std::vector<std::vector<int>> result;
        int i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            // find intersection
            int start = std::max(firstList[i][0], secondList[j][0]);
            int end = std::min(firstList[i][1], secondList[j][1]);

            if (start <= end) {
                // the intersection is valid interval
                result.push_back({start, end});
            }

            if (firstList[i][1] <= secondList[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};

// Runtime: O(N+M)
// Memory: O(N+M)
