/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void swapTree(TreeNode *t) {
        if(t == NULL) return;
        TreeNode *temp = t->right;
        t->right = t->left;
        t->left = temp;

        swapTree(t->right);
        swapTree(t->left);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        swapTree(root);
        return root;
    }
};