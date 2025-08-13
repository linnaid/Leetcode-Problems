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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }

        queue<TreeNode*> nodes;
        queue<int> depth;
        nodes.push(root);
        depth.push(0);

        int max_depth = -1;
        while(!nodes.empty()) {
            int deep = depth.front();
            depth.pop(); 
            max_depth = max(deep, max_depth);
            TreeNode* node = nodes.front();
            nodes.pop();
            if(deep >= ans.size()) {
                ans.push_back(node->val);
            } else {
                if(ans[deep] < node->val) {
                    ans[deep] = node->val;
                }
            }
            if(node->left) {
                nodes.push(node->left);
                depth.push(deep + 1);
            }
            if(node->right) {
                nodes.push(node->right);
                depth.push(deep + 1);
            }
        }
        return ans;
    }
};