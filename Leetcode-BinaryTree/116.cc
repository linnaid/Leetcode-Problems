/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return nullptr;
        }
        
        queue<Node*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
           int size = nodes.size();

           for(int i = 0; i < size; i++) {
                Node* node = nodes.front();
                nodes.pop();

                if(i < size - 1) {
                    node->next = nodes.front();
                }

                if(node->left != nullptr) {
                    nodes.push(node->left);
                }

                if(node->right != nullptr) {
                    nodes.push(node->right);
                }
           }            

        }

        return root;
    }
    
};