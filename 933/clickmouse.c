/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int L, int R) {
    int sum = 0;
    if(root == NULL)
        return 0;
    if(root->val < L)
        return rangeSumBST(root->right, L, R);
    else if(root->val > R)
        return rangeSumBST(root->left, L, R);
    else{
        if(root->val > L)
            sum += rangeSumBST(root->left, L, R);
        sum += root->val;
        if(root->val < R)
            sum += rangeSumBST(root->right, L, R);
        return sum;
    }
}
