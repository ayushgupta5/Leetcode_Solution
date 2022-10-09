class Solution {
public:
    bool findTarget(TreeNode* root, int sum) {
        unordered_set<int> mp;
        stack<TreeNode*> st;
        while(root || st.size()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top(); st.pop();
            if(mp.find(sum-(root->val))!=mp.end()) return 1;
            mp.insert(root->val);
            root=root->right;
        }
        return 0;
    }
};