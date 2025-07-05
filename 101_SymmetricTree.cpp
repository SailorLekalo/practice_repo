struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };

class Solution {
    bool isMirror(TreeNode* left, TreeNode* right) {
        // end valid mirror on empty leaf children
        if (left == nullptr && right == nullptr) {
            return true;
        }

        if (left == nullptr || right == nullptr) {
            return false;
        }

        // mirroring: equal root values, first left subtree to second right, first right subtree to second left
        return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};

// Runtime: O(N)
// Memory: O(H), H - height
