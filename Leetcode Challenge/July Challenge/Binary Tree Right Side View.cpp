/*
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
class Solution {
public:
    void fun(TreeNode * root, vector<int> &ans, int level){
        if(!root) return;
        if(ans.size() == level) ans.push_back(root->val);
        fun(root->right, ans, level+1);
        fun(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        fun(root, ans, 0);
        return ans;
    }
};






class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.front(); q.pop();
                if(i==n-1) ans.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }
        return ans;
    }
};