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
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> arr;
            stack<TreeNode*> tre;
    
            if(root == nullptr)
            {
                return arr;
            }
            while(root != nullptr || !tre.empty())
            {
                while(root != nullptr)
                {
                    arr.emplace_back(root->val);
                    tre.emplace(root);
                    root = root->left;
                }
                root = tre.top();
                tre.pop();
                root = root->right;
            }
            return arr;
        }
    };