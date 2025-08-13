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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        queue<TreeNode*> nodes;
        queue<int> nums;
        nodes.push(root);
        nums.push(root->val);
        while(!nodes.empty()) {
            TreeNode* node = nodes.front();
            int num = nums.front();
            nodes.pop();
            nums.pop();
            if(node->left == nullptr && node->right == nullptr) {
                if(num == targetSum) {
                    return true;
                }
                continue;
            }
            if(node->left != nullptr) {
                nodes.push(node->left);
                nums.push(num + node->left->val);
            }
            if(node->right != nullptr) {
                nodes.push(node->right);
                nums.push(num + node->right->val);
            }
        }
        return false;
    }
};