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
    bool check(TreeNode* node) {
        return (!node->left && !node->right);
    }
    int dfs(TreeNode* root) {
        int ans = 0;
        if(root->left) {
            ans += check(root->left) ? root->left->val : dfs(root->left);
        }
        if(root->right) {
            ans += dfs(root->right);
        }
        return ans;
    } 
    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};