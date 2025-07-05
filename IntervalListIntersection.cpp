/*

Дано два списка кортежей вида (a,b). Это — свободные отрезки времени двух людей.
Найти самый ранний момент, когда их свободное время пересечётся на промежуток duration

Input:
windows_a = [ (10,50), (60,120), (140,180) ]
windows_b = [ (0,15), (50,70)]
duration = 8
Output:
(60,68)

 */

#include <vector>


#include <iostream>
#include <sstream>
#include <string>

std::pair<int, int> solve(const std::vector<std::pair<int, int>> &A, const std::vector<std::pair<int, int>> &B, int duration) {
    int A_p = 0;
    int B_p = 0;

    while (A_p < A.size() && B_p < B.size()) {
        // intersection - latest start and earliest end
        int start = std::max(A[A_p].first, B[B_p].first);
        int end = std::min(A[A_p].second, B[B_p].second);

        if (end - start >= duration) {
            // first duration number of minutes in the intersection
            return std::make_pair(start, start + duration);
        }

        // move to the next pair via the element that ended earlier
        if (A[A_p].second == end) {
            ++A_p;
        } else {
            ++B_p;
        }
    }

    return std::make_pair(-1, -1);
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream issA(line);
    std::vector<std::pair<int, int>> A;

    int time, value;
    while (issA >> time >> value) {
        A.push_back({time, value});
    }

    std::getline(std::cin, line);
    std::istringstream issB(line);
    std::vector<std::pair<int, int>> B;

    while (issB >> time >> value) {
        B.push_back({time, value});
    }

    int duration;
    std::cin >> duration;

    auto result = solve(A, B, duration);
    std::cout << "(" << result.first << ", " << result.second << ") ";

    return 0;
}

// Runtime: O(A.size() + B.size())
// Memory: O(1)
