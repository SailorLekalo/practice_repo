/*

Даны два списка чисел A и B одинаковой длины N.

Нужно вернуть массив result длины N, где result[k]
    — это размер пересечения префиксов A[0...k] и B[0...k].

Без учета кратности: result[k] — это количество уникальных чисел,
    которые есть и в A[0...k], и в B[0...k].

A = [5, 1, 7, 4]
B = [7, 1, 5, 4]

Ожидаемый результат: [0, 1, 3, 4]

*/

#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> solve(int n, const std::vector<int>& A, const std::vector<int>& B) {
    std::unordered_set<int> single_A;
    std::unordered_set<int> single_B;
    // to handle not counting duplicates again
    std::unordered_set<int> unique_elems;

    int count = 0;
    std::vector<int> result;
    result.reserve(n);

    for (int i = 0; i < n; i++) {
        int a = A[i];
        int b = B[i];

        if (a == b) {
            // already a pair but only if not matched before
            if (unique_elems.find(a) == unique_elems.end()) {
                ++count;
                unique_elems.insert(a);
            }
        } else {
            if (single_B.count(a)) {
                // B has unmatched pair for current of A
                if (unique_elems.find(a) == unique_elems.end()) {
                    ++count;
                    single_B.erase(a);
                    unique_elems.insert(a);
                }
            } else {
                // or A now has an unmatched number to consider later
                single_A.insert(a);
            }

            if (single_A.count(b)) {
                // A has unmatched pair for current of B
                if (unique_elems.find(b) == unique_elems.end()) {
                    ++count;
                    single_A.erase(b);
                    unique_elems.insert(b);
                }
            } else {
                single_B.insert(b);
            }
        }
        result.push_back(count);
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    std::vector<int> B(n);

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    std::vector<int> result = solve(n, A, B);
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}

// Runtime: O(n)
// Memory: O(n)
