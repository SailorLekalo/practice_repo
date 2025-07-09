#include <stack>
#include <vector>

class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const std::vector<NestedInteger> &getList() const;
};

class NestedIterator {
    // to iterate the recursive structure
    std::stack<NestedInteger> s;

public:
    NestedIterator(std::vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            s.push(nestedList[i]);
        }
    }

    int next() {
        // this is a number already thanks to hasnext()
        NestedInteger i = s.top();
        s.pop();
        return i.getInteger();
    }

    bool hasNext() {
        while (!s.empty()) {
            NestedInteger curr = s.top();
            if (curr.isInteger()) {
                return true;
            }

            s.pop();
            const std::vector<NestedInteger>& nest = curr.getList();
            // put elems of nested list to stack in reverse order
            for (int i = nest.size() - 1; i >= 0; --i) {
                s.push(nest[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// Runtime: O(1)
// Memory: O(n)
