/*
Даны два упорядоченных по времени списка измерений A и B.
Каждый список представляет собой набор пар (время, значение)
    и задает ступенчатую функцию.

До первого измерения (t=0) значение функции равно 0.
В момент времени t первого измерения значение функции устанавливается в value
    и сохраняется таким до следующего измерения.
Цель: "Слить" эти два графика, чтобы получить новый список пар
    (время, суммарное_значение), который представляет собой сумму
    значений функций A и B на каждом интервале времени.

Пример:
A = [(1, 5), (5, 10)]
B = [(2, 3), (7, -2)]

Ожидаемый результат: [(1, 5), (2, 8), (5, 13), (7, 8)]

 */

#include <vector>

#include <iostream>
#include <sstream>
#include <string>

std::pair<int, int> solve(const std::vector<std::pair<int, int> > &A, const std::vector<std::pair<int, int> > &B) {
    std::vector<std::pair<int, int>> result;
    result.reserve(A.size() + B.size());

    int A_p = 0;
    int B_p = 0;
    int last_A = 0;
    int last_B = 0;

    while (A_p < A.size() && B_p < B.size()) {
        if (A[A_p].first < B[B_p].first) {
            int val = A[A_p].second;
            result.push_back(std::make_pair(A[A_p].first, val + last_B));
            last_A = val;
            A_p++;
        } else if (A[A_p].first > B[B_p].first) {
            int val = B[B_p].second;
            result.push_back(std::make_pair(B[B_p].first, val + last_A));
            last_B = val;
            B_p++;
        } else {
            int val_A = A[A_p].second;
            int val_B = B[B_p].second;
            result.push_back(std::make_pair(B[B_p].first, val_A + val_B));
            last_A = val_A;
            last_B = val_B;
            A_p++;
            B_p++;
        }
    }

    for (int i = A_p; i < A.size(); i++) {
        result.push_back(std::make_pair(A[i].first, A[i].second + last_B));
    }

    for (int i = B_p; i < B.size(); i++) {
        result.push_back(std::make_pair(B[i].first, B[i].second + last_A));
    }

    return result;
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

    auto result = solve(A, B);

    for (const auto& p : result) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}

// Runtime: O(A.size() + B.size())
// Memory: O(A.size() + B.size())
