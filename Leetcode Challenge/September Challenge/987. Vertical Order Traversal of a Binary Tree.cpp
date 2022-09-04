/*987. Vertical Order Traversal of a Binary Tree
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at 
positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting
from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. 
In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]   */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(q.size()){
            auto p=q.front(); q.pop();
            root=p.first;
            int x=p.second.first, y=p.second.second;
            nodes[x][y].insert(root->val);
            if(root->left) q.push({root->left, {x-1, y+1}});
            if(root->right) q.push({root->right, {x+1, y+1}});
        }
        for(auto p: nodes){
            vector<int> col;
            for(auto r: p.second){
                col.insert(col.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

