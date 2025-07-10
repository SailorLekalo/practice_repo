/*

Вам дан массив временных меток timestamps (целые числа),
    когда происходили события (например, клики пользователя).
Также дано число X — длина временного окна.

Найдите максимальное количество событий,
    которое попало в любое возможное временное окно длиной X.

Пример:
timestamps = [1, 5, 8, 9, 11, 15]
X = 5

Окно [1, 5] содержит [1, 5] (2 события).
Окно [5, 9] содержит [5, 8, 9] (3 события).
Окно [8, 12] содержит [8, 9, 11] (3 события).
Окно [11, 15] содержит [11, 15] (2 события).
Ответ: 3

 */

#include <algorithm>
#include <vector>

int maxActivity(const std::vector<int>& events, int X) {
    int max = 0;
    if (!events.empty()) {
        std::sort(events.begin(), events.end());
    }

    int l_p = 0;
    for (int r_p = 0; r_p < events.size(); ++r_p) {
        // maintain valid window after increasing r_p
        while (events[r_p] - events[l_p] >= X) {
            ++l_p;
        }
        max = std::max(max, r_p - l_p + 1);
    }

    return max;
}

// Runtime: O(N logN)
// Memory: O(1)
