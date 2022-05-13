/*
117. Populating Next Right Pointers in Each Node II
Given a binary tree
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example 1:


Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, 
just like in Figure B. The serialized output is in level order as connected by the next pointers, 
with '#' signifying the end of each level.
*/
class Solution {
public:
    void fun(Node *root) {
        queue<Node *> q;
        Node *curr=root;
        vector<vector<Node *>> v;
        q.push(root);
        while(q.size()) {
            int n=q.size();
            vector<Node *> a;
            for(int i=0;i<n;i++) {
                root= q.front(); q.pop();
                a.push_back(root);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            v.push_back(a);
        }
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].size();j++) {
                if(j==v[i].size()-1) v[i][j]->next=NULL;
                else v[i][j]->next=v[i][j+1];
            }
        }
    }
    Node* connect(Node* root) 
    {
        if(!root) return NULL;
        fun(root);
        return root;
    }
};