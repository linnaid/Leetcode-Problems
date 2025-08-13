/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            vector<int> nums;
            int size = nodes.size();
            for(int i = 0; i < size; i++) {
                Node* node = nodes.front();
                nodes.pop();
                nums.push_back(node->val);
                for(Node* it : node->children) {
                        nodes.push(it);
                }
            }
            ans.push_back(move(nums));
        }
        return ans;
    }
};