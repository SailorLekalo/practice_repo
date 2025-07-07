/*

Дано бинарное дерево, в узлах которого находятся символы.
Нужно найти два любых поддерева, у которых одинаковый набор символов.
Структура поддеревьев не важна. Если таких пар несколько, найти любую.

Поддерево A -> B и поддерево B -> A считаются "эквивалентными",
    так как у обоих набор символов {A, B}.

 */

#include <vector>
#include <unordered_map>

#include <iostream>

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

std::unordered_map<int, TreeNode*> mask_to_node;
std::pair<TreeNode*, TreeNode*> result = {nullptr, nullptr};

int dfs(TreeNode* root) {
    // don't move further if found the result
    if (root == nullptr || result.first != nullptr) {
        return 0;
    }

    int left = dfs(root->left);
    int right = dfs(root->right);

    int root_mask = 1 << (root->val - 'A');
    int mask = root_mask | left | right;

    if (mask_to_node.count(mask)) {
        // the mask for the root was already found
        result = {root, mask_to_node[mask]};
    } else {
        mask_to_node[mask] = root;
    }

    // root mask to parent
    return mask;
}

std::pair<TreeNode*, TreeNode*> solve(TreeNode* root) {
    dfs(root);
    return result;
}

// Runtime: O(N)
// Memory: O(N) (if all masks are unique)
