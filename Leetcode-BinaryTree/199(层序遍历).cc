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
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int, int> middle;
        int depth = -1;

        stack<TreeNode*> trees;
        stack<int> nodes;
        trees.push(root);
        nodes.push(0);

        while(!trees.empty()) {
            TreeNode* node = trees.top();
            trees.pop();
            int deep = nodes.top();
            nodes.pop();
            if(node != nullptr) {
                depth = max(depth, deep);
                if(middle.find(deep) == middle.end()) {
                    middle[deep] = node->val;
                }

                trees.push(node->left);
                trees.push(node->right);
                nodes.push(deep + 1);
                nodes.push(deep + 1);
            }          
        }

        vector<int> ans;
        for(int i = 0; i <= depth; i++) {
            ans.push_back(middle[i]);
        }

        return ans;
    }
};