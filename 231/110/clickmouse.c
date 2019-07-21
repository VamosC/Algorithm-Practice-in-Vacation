/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int depth(struct TreeNode* T){
    if(T == NULL)
        return 0;
    return max(depth(T->left),depth(T->right))+1;
}
bool isBalanced(struct TreeNode* root) {
    if(root == NULL)
        return true;
    int left = depth(root->left);
    int right = depth(root->right);
    return (abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right));
}
