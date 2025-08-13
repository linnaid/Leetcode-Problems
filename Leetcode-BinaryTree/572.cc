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
    bool check(TreeNode*root, TreeNode* sub) {
        if(!root && !sub) {
            return true;
        }
        if((!root && sub) || (root && !sub) || (root->val != sub->val)) {
            return false;
        }
        return check(root->left, sub->left) && check(root->right, sub->right);
    }
    bool dfs(TreeNode* root, TreeNode* sub) {
        if(!root) {
            return false;
        }
        return check(root, sub) || dfs(root->left, sub) || dfs(root->right, sub);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};