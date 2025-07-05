/*

Дан бинарный массив nums (состоит только из 0 и 1).
Найдите максимальное количество идущих подряд единиц,
    если вы можете "перевернуть" (изменить с 0 на 1) не более одного нуля.

              l
nums = [1, 0, 1, 1, 0]
                       r

1

4

Ответ: 4
       l
11111100
       r

  l
1011011
       r

m 5
c 1

 */

#include <vector>

#include <iostream>
#include <sstream>
#include <string>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max = 0;
    int l_p = 0;
    // curr num of zeros
    int count = 0;

    for (int r_p = 0; r_p < nums.size(); r_p++) {
        if (nums[r_p] == 0) {
            ++count;

            if (count > 1) {
                // consider window from prev iteration
                max = std::max(max, r_p - l_p);
            }

            while (count > 1) {
                if (nums[l_p] == 0) {
                    --count;
                }
                ++l_p;
            }
        }
    }

    // consider last valid window
    return std::max(max, (int)nums.size() - l_p);
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream issA(line);
    std::vector<int> A;

    int value;
    while (issA >> value) {
        A.push_back(value);
    }

    auto result = findMaxConsecutiveOnes(A);
    std::cout << result;

    return 0;
}

// Runtime: O(n)
// Memory: O(1)
