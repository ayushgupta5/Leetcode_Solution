/*114. Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 

Follow up: Can you flatten the tree in-place (with O(1) extra space)?       */
class Solution {
public:
    /*
    void flatten(TreeNode* root) {
        if(root) {
            TreeNode *leftptr=root->left;
            TreeNode *rightptr=root->right;
            root->left=NULL;
            flatten(leftptr);
            flatten(rightptr);
            root->right=leftptr;
            while(root->right) root=root->right;
            root->right=rightptr;
        }
    }
    */
    //Space: O(1)
    void flatten(TreeNode* root) {
        if(!root) return;
        while(root){
            if(root->left){
                TreeNode *left=root->left;
                TreeNode *curr=left;
                while(curr->right) curr=curr->right;
                curr->right=root->right;
                root->left=NULL;
                root->right=left;
            }
            root=root->right;
        }
    }
};


