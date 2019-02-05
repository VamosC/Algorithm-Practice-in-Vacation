/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define INFINIY 100000
int getMinimumDifference(struct TreeNode* root) {
    struct TreeNode* Stack[30];
    int TopOfStack = -1;
    int base = -1;
    int diff;
    int minDiff = INFINIY;
    while(1){
        for(; root != NULL; root = root->left)
            Stack[++TopOfStack] = root;
        if(TopOfStack == -1)
            break;
        root = Stack[TopOfStack--];
        if(base == -1)
            base = root->val;
        else{
            diff = root->val - base;
            if(diff < minDiff)
                minDiff = diff;
            base = root->val;
        }
        root = root->right;
    } 
    return minDiff; 
}
