/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return sum - root->val == 0;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
