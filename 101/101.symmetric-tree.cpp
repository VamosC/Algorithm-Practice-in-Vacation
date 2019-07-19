/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        if (root)
            return isSymmetricNode(root->left, root->right);
        return true;
    }
    bool isSymmetricNode(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p && q)
        {
            if (p->val != q->val)
                return false;
            return isSymmetricNode(p->left, q->right) && isSymmetricNode(p->right, q->left);
        }
        return false;
    }
};
