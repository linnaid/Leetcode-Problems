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
    
        void panduan(vector<int>& arr, TreeNode* root)
        {
            if(!root)
            {
                return;
            }
            arr.push_back(root->val);
            panduan(arr, root->left);
            panduan(arr, root->right);
        }
    
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> arr;
            panduan(arr, root);
            return arr;
        }
    };