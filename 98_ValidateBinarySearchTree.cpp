#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // for the current node, evaluate if it respects the bounds, and further set it as bound
    bool isValid(TreeNode* root, long long min_bound, long long max_bound) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= min_bound || root->val >= max_bound) {
            return false;
        }

        return isValid(root->left, min_bound, root->val) && isValid(root->right, root->val, max_bound);
    }

public:
    bool isValidBST(TreeNode* root) {
        // to handle min and max int values
        return isValid(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
};

// Runtime: O(N)
// Memory: O(H), H - height
