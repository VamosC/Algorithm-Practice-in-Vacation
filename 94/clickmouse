/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int count = 0;
    int* Inorder = (int*)malloc(sizeof(int)*100);
    struct TreeNode* Stack[100];
    int TopOfStack = -1;
    while(1){
        while(root!=NULL){
            Stack[++TopOfStack] = root;
            root = root->left;
        }
        if(TopOfStack == -1)
            break;
        root = Stack[TopOfStack--];
        Inorder[count++] = root->val;
        root = root->right;
    }
    *returnSize = count;
    return Inorder;
}
