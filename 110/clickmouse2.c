/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b){
    if( a > b )
        return a;
    return b;
}

int DFS(struct TreeNode* T, int depth)
{
    if(T == NULL)
        return depth;
    int left, right;
    left = DFS(T->left, depth+1);
    right = DFS(T->right, depth+1);
    if(abs(left-right) > 1)
        return -1;
    else 
        return max(left,right);
}

bool isBalanced(struct TreeNode* root) 
{
    if(DFS(root, 0) == -1)
        return false;
    else
        return true;
}
