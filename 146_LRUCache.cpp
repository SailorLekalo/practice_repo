#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;
    // to move elems in O(1) and order the usages
    std::list<std::pair<int, int>> items_list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> items_map;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (items_map.find(key) == items_map.end()) {
            return -1;
        }

        // make elem 'freshest'
        items_list.splice(items_list.begin(), items_list, items_map[key]);
        return items_map[key]->second;
    }
    
    void put(int key, int value) {
        if (items_map.find(key) != items_map.end()) {
            items_map[key]->second = value;
            // we just used the elem
            items_list.splice(items_list.begin(), items_list, items_map[key]);
            return;
        }

        if (items_map.size() == capacity) {
            // the oldest elem to delete
            int key_del = items_list.back().first;
            items_list.pop_back();
            items_map.erase(key_del);
        }

        items_list.push_front({key, value});
        items_map[key] = items_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
*/

// Runtime: O(1)
