/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int** Order = (int**)calloc(780, sizeof(int*));
    int i;
    for(i = 0; i < 780; i++)
    	Order[i] = (int*)malloc(sizeof(int)*780);
    *columnSizes = (int*)calloc(780, sizeof(int));
    *returnSize = 1;
    int deep;
    struct TreeNode* Queue[1100];
    int Front = 0;
    int Rear = -1;
    int size = 0;
    int depth[1100] = {0};
    int Dfront = 0;
    int Drear = -1;
    deep = 0;
    if(root!=NULL){
    	Queue[++Rear] = root;
    	size++;
    	depth[++Drear] = 0;
    }
    while(size != 0){
    	root = Queue[Front++];
    	size--;
    	deep = depth[Dfront++];
    	Order[deep][(*columnSizes)[deep]++] = root->val;
    	deep++;
    	if(root->left!=NULL){
    		Queue[++Rear] = root->left;
    		size++;
    		depth[++Drear] = deep;
    	}
    	if(root->right!=NULL){
    		Queue[++Rear] = root->right;
    		size++;
    		depth[++Drear] = deep;
    	}
    }
    *returnSize = deep;
    return Order;
}
