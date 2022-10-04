class Solution {
public:
    bool f(TreeNode *root, int target) {
        if(!root) return 0;
        target-=root->val;
        if(!root->left && !root->right) return target==0;
        bool x = f(root->left, target);
        bool y = f(root->right, target);
        return x|y;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root, targetSum);
    }
};