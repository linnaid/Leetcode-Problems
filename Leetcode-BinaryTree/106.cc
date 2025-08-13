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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[postorder.size() - 1]);
        auto s = stack<TreeNode*> ();
        s.push(root);
        int index = inorder.size() - 1;
        for(int i = int(postorder.size()) - 2; i >= 0; i--) {
            int post = postorder[i];
            auto node = s.top();
            if(node->val != inorder[index]) {
                node->right = new TreeNode(post);
                s.push(node->right);
            } else {
                while(!s.empty() && s.top()->val == inorder[index]) {
                    node = s.top();
                    s.pop();
                    index--;
                }
                node->left = new TreeNode(post);
                s.push(node->left);
            }
        }
        return root;
    }
};