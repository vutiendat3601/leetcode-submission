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
    int findLeftMin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root->val;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else {
                int minVal = findLeftMin(root->right);
                root->val = minVal;
                root->right = deleteNode(root->right, minVal);
            }
        }
        return root;
    }
};