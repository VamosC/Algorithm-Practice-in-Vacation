/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        stack<int> heights;
        stack<TreeNode *> nodes;
        nodes.push_back(root);
        while (!nodes.empty())
        {
            auto p = nodes.top();
            while (p)
            {
                if (p->left)
                    nodes.push_back(p->left);
                p = p->left;
            }
            auto q = nodes.top();
        }
    }
};
