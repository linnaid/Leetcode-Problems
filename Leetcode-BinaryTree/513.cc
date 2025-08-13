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
    void dfs(TreeNode* root, int& ans, int& maxlevel, int high) {
        if(root == nullptr) {
            return;
        }
        high++;
        dfs(root->left, ans, maxlevel, high);
        dfs(root->right, ans, maxlevel, high);
        if(high > maxlevel) {
            ans = root->val;
            maxlevel = high;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        int maxlevel = 0;
        dfs(root, ans, maxlevel, 0);
        return ans;
    }
};