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
    void Handle(Node* &nextstart, Node* &nextnode, Node* &node) {
        if(nextnode) {
            nextnode->next = node;
        }
        if(nextstart == nullptr) {
            nextstart = node;
        }
        nextnode = node;
    }
    Node* connect(Node* root) {
        if(!root) {
            return nullptr;
        }
        Node* node = root;
        while(node) {
            Node* nextnode = nullptr;
            Node* nextstart = nullptr;
            for(Node* i = node; i != nullptr; i = i->next) {
                if(i->left) {
                    Handle(nextstart, nextnode, i->left);
                }
                if(i->right) {
                    Handle(nextstart, nextnode, i->right);
                }
            }
            node = nextstart;
        }
        return root;
    }
};