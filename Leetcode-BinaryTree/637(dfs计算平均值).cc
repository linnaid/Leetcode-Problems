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
    void dfs(TreeNode* root, int level, vector<int>& counts, vector<double>& sums) {
        if(root == nullptr) {
            return;
        }
        if(level < sums.size()) {
            sums[level] += root->val;
            counts[level] += 1;
        } else {
            sums.push_back(1.0 * root->val);
            counts.push_back(1);
        }
        dfs(root->left, level + 1, counts, sums);
        dfs(root->right, level + 1, counts, sums);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> counts;
        vector<double> sums;
        dfs(root, 0, counts, sums);
        vector<double> ans;
        int size = sums.size();
        for(int i = 0; i < size; i++) {
            ans.push_back(sums[i]/counts[i]);
        }
        return ans;
    }
};