/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> seq;
    	TreeNode* p;
    	stack<TreeNode*> treeNodes;
    	if(root == NULL)
    		return seq;
    	p = root;
    	do
    	{
    		while(p)
    		{
    			treeNodes.push(p);
    			p = p->left;
    		}
    		p = treeNodes.top();
    		seq.push_back(p->val);
    		treeNodes.pop();
    		p = p->right;
    	}while(p && !treeNodes.empty());
        return seq;
    }
};