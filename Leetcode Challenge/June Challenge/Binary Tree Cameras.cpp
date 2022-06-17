/*
968. Binary Tree Cameras
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
*/
class Solution {
public:
    int camera = 0;
    int fun(TreeNode *root) {
        if(!root) return 1;
        int leftChild = fun(root->left);
        int rightChild = fun(root->right);
        if(leftChild == -1 || rightChild == -1) {
            camera++;
            return 0;
        }
        if(leftChild == 0 || rightChild == 0) return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(fun(root) == -1) camera++;
        return camera;
    }
};