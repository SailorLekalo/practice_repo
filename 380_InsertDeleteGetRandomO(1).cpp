#include <vector>
#include <unordered_map>

#include <cstdlib>

class RandomizedSet {
private:
    // maintain indices of numbers in vector to handle valid random in O(1)
    std::unordered_map<int, int> vec_ids;
    std::vector<int> nums;

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (vec_ids.find(val) == vec_ids.end()) {
            // add elem "at the end"
            vec_ids[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (vec_ids.find(val) != vec_ids.end()) {
            int idx = vec_ids[val];
            int last = nums.back();
            // swap last vector elem with the one to be deleted
            nums[idx] = last;
            nums.pop_back();

            // update the link to the new index
            vec_ids[last] = idx;
            vec_ids.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[std::rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
*/

// Runtime: O(1)
// Memory: O(num of insert calls)
