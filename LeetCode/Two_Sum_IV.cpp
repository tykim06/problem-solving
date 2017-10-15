#include <stdio.h>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<int, int> numberMap;
    bool isEnableSum;
    int k;

    void searchSum(TreeNode* node) {
        if(node == NULL || isEnableSum) return;
        if(numberMap[k - node->val] == 1) {
            isEnableSum = true;
            return;
        }

        numberMap[node->val] = 1;

        searchSum(node->right);
        searchSum(node->left);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL || k == 0) return false;

        isEnableSum = false;
        numberMap[root->val] = 1;
        this->k = k;

        searchSum(root->right);
        searchSum(root->left);

        return isEnableSum;
    }
};