#include <stdlib.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int _key;

    bool isOneChildTree(TreeNode *node) {
        if(!node->left and !node->right) return true;
        if(node->left and node->right) return false;

        if(node->left) return isOneChildTree(node->left);
        else return isOneChildTree(node->right);
    }

    int findLeafNode(TreeNode *node, TreeNode *parentNode, bool isLeft) {
        if(!node->left and !node->right) {
            if(parentNode) {
                if(isLeft) parentNode->left = NULL;
                else parentNode->right = NULL;   
            }
            return node->val;
        }

        if(node->left) return findLeafNode(node->left, node, true);
        else return findLeafNode(node->right, node, false);
    }

    void findKeyNode(TreeNode *node, TreeNode *parentNode, bool isLeft) {
        if(!node) return;

        if(node->val == _key) {
            if(isOneChildTree(node->left)) {
            } else if(isOneChildTree(node->right)) {

            }
            int val = findLeafNode(node, parentNode, isLeft);
            if(val != node->val) {
                node->val = val;
            }
            return;
        }

        findKeyNode(node->left, node, true);
        findKeyNode(node->right, node, false);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key) {
            int val = findLeafNode(root, NULL, false);
            if(val == root->val) return NULL;
            else {
                root->val = val;
                return root;
            }
        }
        _key = key;

        findKeyNode(root, NULL, false);

        return root;
    }
};