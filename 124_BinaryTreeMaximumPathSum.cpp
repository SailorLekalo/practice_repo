#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sum = 0;

    // Updates max sum with nonsplit path sum and returns max sum going to one of the children
    int maxSumDFS(TreeNode* root) {
        // max sum possible with left/right subtree paths
        int left_sum = 0;
        int right_sum = 0;

        if (root->left != nullptr) {
            left_sum = maxSumDFS(root->left);
        }

        if (root->right != nullptr) {
            right_sum = maxSumDFS(root->right);
        }

        left_sum = std::max(0, left_sum);
        right_sum = std::max(0, right_sum);
        // nonsplit path involving root and paths from both subtrees
        sum = std::max(sum, left_sum + root->val + right_sum);

        return root->val + std::max(std::max(left_sum, 0), right_sum);
    }

public:
    int maxPathSum(TreeNode* root) {
        // path must include at least one node
        sum = root->val;
        return std::max(maxSumDFS(root), sum);
    }
};

/*
      1
  2        2
1  9   20   -40
    -15 30  7 -3

54

11
42
*/
