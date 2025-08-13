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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> d;
        TreeNode* prev = nullptr;

        if(root == nullptr) {
            return ans;
        }

        while(root != nullptr || !d.empty()) {
            while(root != nullptr) {
                d.push(root);
                root = root->left;
            }

            root = d.top();
            d.pop();
            if(root->right == nullptr || root->right == prev) {
                ans.push_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                d.push(root);
                root = root->right;
            }
            
        }
        return ans;
    }
};