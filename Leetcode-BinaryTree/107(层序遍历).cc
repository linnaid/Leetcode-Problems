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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <vector <int>> ans;
        if (!root) {
            return ans;
        }
        queue <TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            int size = nodes.size();
            ans.push_back(vector <int> ());
            
            for(int i = 1; i <= size; i++) {
                TreeNode* node = nodes.front();
                nodes.pop();
                ans.back().push_back(node->val);
                if(node->left) nodes.push(node->left);
                if(node->right) nodes.push(node->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};