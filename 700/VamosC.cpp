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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL) {
        	if(val < root->val)
        		root = root->left;
        	else if(val > root->val)
        		root = root->right;
        	else
        		break;
        }
        return root;
    }
};