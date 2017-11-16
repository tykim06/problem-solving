#include <stdlib.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(!root) return;

    	queue<TreeLinkNode*> q;
    	q.push(root);

    	int count = q.size();
    	TreeLinkNode *prevNode = NULL, *node = NULL;

    	while(!q.empty()) {
    		if(count == 0) count = q.size();

    		node = q.front();
    		q.pop();
    		count--;

            if(!node) return;
    		if(prevNode) prevNode->next = node;
    		
    		if(count > 0) prevNode = node;
    		else prevNode = NULL;
            
            q.push(node->left);
            q.push(node->right);
    	}   
    }
};