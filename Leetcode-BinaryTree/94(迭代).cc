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
    
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> arr;
            stack<TreeNode*> sa;
            while(root != nullptr || !sa.empty())
            {
                while(root != nullptr)
                {
                    sa.push(root);
                    root = root->left;
                }
                root = sa.top();
                sa.pop();
                arr.push_back(root->val);
                root = root->right;
            }
            return arr;
        }
    };