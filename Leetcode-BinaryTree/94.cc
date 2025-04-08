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
        void panduan(TreeNode* root, vector<int>& arr)
        {
            if(!root)
            {
                return;
            }
            panduan(root->left, arr);
            arr.push_back(root->val);
            panduan(root->right, arr);
        }
    
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> arr;
            panduan(root, arr);
            return arr;
        }
    };