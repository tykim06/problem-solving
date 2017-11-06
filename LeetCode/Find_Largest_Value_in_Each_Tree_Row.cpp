#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    std::vector<int> largestValueVs;

    void travelTree(TreeNode *tree, int depth) {
        if(tree == NULL) return;

        if(largestValueVs.size() == depth) {
            largestValueVs.push_back(tree->val);
        } else if(largestValueVs[depth] < tree->val) {
            largestValueVs[depth] = tree->val;
        }

        travelTree(tree->left, depth+1);
        travelTree(tree->right, depth+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return largestValueVs;

        largestValueVs.push_back(root->val);

        travelTree(root->left, 1);
        travelTree(root->right, 1);

        return largestValueVs;
    }
};