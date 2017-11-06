#include <queue>
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
    std::vector<std::vector<int> > travelVs;

    void travelTree(TreeNode *tree, int depth) {
        if(tree == NULL) return;

        if(travelVs.size() == depth) {
            std::vector<int> travelV;
            travelV.push_back(tree->val);
            travelVs.push_back(travelV);
        } else if(depth%2 == 0) {
            travelVs[depth].push_back(tree->val);
        } else {
            travelVs[depth].insert(travelVs[depth].begin(), tree->val);
        }

        travelTree(tree->left, depth+1);
        travelTree(tree->right, depth+1);
    }
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return travelVs;

        std::vector<int> travelV;
        travelV.push_back(root->val);
        travelVs.push_back(travelV);

        travelTree(root->left, 1);
        travelTree(root->right, 1);

        return travelVs;
    }
};