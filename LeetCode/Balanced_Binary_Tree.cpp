#include <stdlib.h>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isHeightBalanced;
    int getDepth(TreeNode *node, int depth) {
        if(!node) return depth-1;

        int rDepth = getDepth(node->right, depth+1);
        int lDepth = getDepth(node->left, depth+1);

        if(abs(rDepth - lDepth) > 1) isHeightBalanced = false;

        return max(rDepth, lDepth);
    }
public:
    bool isBalanced(TreeNode* root) {
        isHeightBalanced = true;
        if(!root) return isHeightBalanced;

        int rDepth = getDepth(root->right, 1);
        int lDepth = getDepth(root->left, 1);

        if(abs(rDepth - lDepth) > 1) isHeightBalanced = false;

        return isHeightBalanced;
    }
};