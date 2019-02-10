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
    struct TreeNode* stack[20];
    int TopOfStack = -1;
    if(root == NULL)
        return 0;
    else{
        while(1){
            for(; root != NULL; root = root->left)
                stack[++TopOfStack] = root;
            if(TopOfStack < 0)
                break;
            root = stack[TopOfStack--];
            if(root->val <= R && root->val >= L)
                sum += root->val;
            root = root->right;
        }
        return sum;
    }
}
