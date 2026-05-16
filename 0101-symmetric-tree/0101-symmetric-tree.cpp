/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool isSymmetric(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) {
            return 1;
        }
        if (!node1 || !node2) {
            return 0;
        }
        return node1->val == node2->val &&
               isSymmetric(node1->left, node2->right) &&
               isSymmetric(node1->right, node2->left);
    }

public:
    bool isSymmetric(TreeNode* root) { return isSymmetric(root, root); }
};