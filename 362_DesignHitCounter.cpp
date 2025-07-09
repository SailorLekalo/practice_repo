#include <algorithm>
#include <vector>

class HitCounter {
    std::vector<int> timestamps;
    // number of hits made in this particular timestamp second
    std::vector<int> hits;

public:
    HitCounter() {
        timestamps.resize(300, 0);
        hits.resize(300, 0);
    }

    void hit(int timestamp) {
        // "cycling" the entries
        int index = timestamp % 300;
        if (timestamp == timestamps[index]) {
            hits[index]++;
        } else {
            // "new" second, or "old" one which can be overwritten
            timestamps[index] = timestamp;
            hits[index] = 1;
        }
    }

    int getHits(int timestamp) {
        int count = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - timestamps[i] < 300) {
                // timestamp at i is within the needed 5-min interval
                count += hits[i];
            }
        }
        return count;
    }
};

// Runtime: O(1)
// Memory: O(1)
