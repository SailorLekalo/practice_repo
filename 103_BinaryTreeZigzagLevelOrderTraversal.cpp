struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <deque>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        // maintain order of traversals
        std::deque<TreeNode*> deq;

        if (root != nullptr) {
            deq.push_back(root);
        }

        bool even_level = true;
        while (!deq.empty()) {
            std::vector<int> level;
            // fix to track level
            int size = deq.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* curr;
                if (even_level) {
                    // standard BFS queue traversal
                    // process current node
                    curr = deq.front();
                    deq.pop_front();

                    if (curr->left != nullptr) {
                        deq.push_back(curr->left);
                    }

                    if (curr->right != nullptr) {
                        deq.push_back(curr->right);
                    }
                } else {
                    // right to left traversal
                    curr = deq.back();
                    deq.pop_back();

                    // add to front from right child to maintain next level order
                    if (curr->right != nullptr) {
                        deq.push_front(curr->right);
                    }

                    if (curr->left != nullptr) {
                        deq.push_front(curr->left);
                    }
                }

                level.push_back(curr->val);
            }

            result.push_back(level);
            even_level = !even_level;
        }

        return result;
    }
};

/*

       3
  6        9
4   20   7
 15

deq:
20 7 * * 15

res:
3 9 6

l->r    1

*/

// Runtime: O(n)
// Memory: O(n)
