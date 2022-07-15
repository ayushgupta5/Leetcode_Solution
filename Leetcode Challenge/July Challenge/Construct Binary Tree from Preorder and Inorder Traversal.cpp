/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder 
where preorder is the preorder traversal of a binary tree and 
inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/
class Solution {
public:
    TreeNode *f(vector<int> &preorder, vector<int> &inorder, int &rootIndex, int lo, int hi) {
        if(lo > hi) return NULL;
        int pivot = lo;
        while(inorder[pivot] != preorder[rootIndex]) pivot++;
        rootIndex++;
        TreeNode *root = new TreeNode(inorder[pivot]);
        root->left = f(preorder, inorder, rootIndex, lo, pivot-1);
        root->right = f(preorder, inorder, rootIndex, pivot+1, hi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIndex = 0, lo = 0, hi = inorder.size()-1;
        return f(preorder, inorder, rootIndex, lo, hi);
    }
};