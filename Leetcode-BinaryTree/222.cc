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
    bool exists(TreeNode* root, int level, int mid) {
        int num = 1;
        num = 1 << (level - 1);
        TreeNode* node = root;
        while(node != nullptr && num > 0) {
            if(!(num & mid)) {
                node = node->left;
            } else {
                node = node->right;
            }
            num >>= 1;
        }
        return node != nullptr;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while(node->left != nullptr) {
            level++;
            node = node->left;
        }

        int min = 1 << level;
        int max = (1 << (level + 1)) - 1;
        while(min < max) {
            int mid = (max - min + 1) / 2 + min;
            if(exists(root, level, mid)) {
                min = mid;
            } else {
                max = mid - 1;
            }
        }
        return min;
    }
};