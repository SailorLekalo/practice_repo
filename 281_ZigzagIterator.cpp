#include <queue>
#include <vector>

class ZigzagIterator {
    // pairs of iterators to the (curr) beginning and to the end for each vector
    std::queue<std::pair<std::vector<int>::iterator, std::vector<int>::iterator>> q;

public:
    ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2) {
        if (!v1.empty()) {
            q.push({v1.begin(), v1.end()});
        }

        if (!v2.empty()) {
            q.push({v2.begin(), v2.end()});
        }
    }

    int next() {
        // curr pair with iterator to the needed val
        auto [curr_it, end_it] = q.front();
        q.pop();

        int val = *curr_it;
        if (++curr_it != end_it) {
            // iterator has not finished the vector yet
            q.push({curr_it, end_it});
        }
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};

// Runtime: O(1)
// Memory: O(1) (# of vectors)
