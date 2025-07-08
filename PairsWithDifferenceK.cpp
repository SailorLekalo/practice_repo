/*

Дан неотсортированный массив целых чисел nums и целое число K.
Задача: найти общее количество пар (nums[i], nums[j]) таких, что
    i != j и nums[i] - nums[j] >= K.

nums = [1, 5, 3, 2], K = 2
Пары: (5, 1), (5, 3), (5, 2), (3, 1)

 */

#include <algorithm>
#include <vector>

long long solve(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int count = 0;
    int n = nums.size();
    // fast right pointer searching for first valid greater number
    int j = 0;

    for (int i = 0; i < n; i++) {
        // second number always goes after the first one
        j = std::max(j, i + 1);
        while (j < n && nums[j] - nums[i] < k) {
            ++j;
        }

        if (j == n) {
            // there can be no pair for all further greater i's
            break;
        }

        count += n - j;
    }

    return count;
}

// Runtime: O(N logN)
// Memory: O(1)/(logN)
