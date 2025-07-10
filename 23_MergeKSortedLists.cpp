#include <queue>
#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // min-heap based on vals
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        // initialize with first non-empty elems
        for (ListNode* head : lists) {
            if (head) {
                pq.push(head);
            }
        }

        ListNode dum_head(0);
        ListNode* tail = &dum_head;

        while (!pq.empty()) {
            // node with min val
            ListNode* min_n = pq.top();
            pq.pop();

            // update curr tail to this node
            tail->next = min_n;
            tail = min_n;

            if (min_n->next) {
                pq.push(min_n->next);
            }
        }
        return dum_head.next;
    }
};

// Runtime: O(N logK)
// Memory: O(K) (# of vectors)
