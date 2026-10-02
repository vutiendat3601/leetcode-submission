/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    vector<int> vals;
    int i, n;

    void collect(TreeNode* root) {
        if (!root)
            return;
        if (root->left)
            collect(root->left);
        vals.push_back(root->val);
        if (root->right)
            collect(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        collect(root);
        i = 0, n = vals.size();
    }
    
    int next() {
        return vals[i++];
    }
    
    bool hasNext() {
        return i < n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */