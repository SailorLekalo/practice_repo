struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int solve(TreeNode* root, int low, int high) {
        int sum = 0;

        if (root != nullptr) {
            // do not go left subtree if value is already min bound or below
            if (root->val > low) {
                sum += solve(root->left, low, high);
            }

            if (root->val < high) {
                sum += solve(root->right, low, high);
            }

            // consider the value itself within both bounds
            if (root->val >= low && root->val <= high) {
                sum += root->val;
            }
        }

        return sum;
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};

// Runtime: O(N)
// Memory: O(H)
