#include <unordered_map>
#include <vector>
#include <algorithm>

#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // map canonical sorted string to the list of all anagrams met
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& str : strs) {
            std::string sorted = str;
            std::sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        // values construct the answer
        for (const auto& pair : groups) {
            result.push_back(pair.second);
        }
        return result;
    }
};

/*

"eat","tea","tan","ate"

aet:    eat, tea, ate
ant:    tan

*/

// Runtime: O(n)
// Memory: O(n)
